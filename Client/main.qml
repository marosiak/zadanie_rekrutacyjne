import QtQuick 2.10
import QtQuick.Controls 2.3

import "Pages"
ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Tabs")
    header: TabBar {
        id: tabBar
        visible: false
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("Zarządzaj")
        }
        TabButton {
            text: qsTr("Ustawienia")
        }
    }
    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex
        ManagePage {}
        SettingsPage {}
    }
    LoginPage {
        id: loginPage
        onLoginClicked: {
            if(loginViewLogin != "" || loginViewPassowrd != ""){
                if(auth.doAuth(loginViewLogin, loginViewPassowrd)){
                    loginPage.visible = false
                    tabBar.visible = true
                } else {
                    dialog.title = "Błąd"
                    dialog.text = auth.getInfo()
                    dialog.open()
                }
            } else {
                dialog.title = "Błąd"
                dialog.text = "Uzupełnij wszystkie pola"
                dialog.open()
            }
        }
        onRegisterClicked: {
            if(registerViewLogin != "" && registerViewPassword != "" && registerViewPasswordAgain != ""){
                if(registerViewPassword != registerViewPasswordAgain){
                    // error
                    dialog.title = "Błąd"
                    dialog.text = "Hasła są różne"
                    dialog.open()
                } else {
                    // register
                    if(auth.register_(registerViewLogin, registerViewPassword)){
                        dialog.title = "Sukces"
                        dialog.text = "Pomyślnie zarejestrowano"
                        dialog.open()
                    } else {
                        dialog.title = "Błąd"
                        dialog.text = auth.getInfo()
                        dialog.open();
                    }
                }
            } else {
                dialog.title = "Błąd"
                dialog.text = "Uzupełnij wszystkie pola"
                dialog.open()
            }
        }
    }
    Dialog {
        id: dialog
        standardButtons: Dialog.Ok
        x: (parent.width/2)-(dialog.width/2)
        y: (parent.height/2)-(dialog.height/2) // Z jakiegoś dziwnego powodu, dialog nie potrafi zrozumieć anchors.centerIn
        property string text: "error"
        width: 200
        height: 150
        Label {
            text: dialog.text
        }
    }
}
