import QtQuick 2.10
import QtQuick.Controls 2.3

Page {
    id: page
    anchors.fill: parent
    signal registerClicked
    signal loginClicked
    property string loginViewLogin: lv_l.text
    property string loginViewPassowrd: lv_h.text
    property string registerViewLogin: rv_l.text
    property string registerViewPassword: rv_h.text
    property string registerViewPasswordAgain: rv_ha.text
    TabBar {
        id: tabBar
        visible: true
        anchors.bottom: stack.top
        anchors.bottomMargin: 6
        anchors.left: stack.left
        anchors.right: stack.right
        TabButton {
            text: qsTr("Zaloguj")
            enabled: stack.depth != 1
            onClicked: {
                stack.pop(loginView)
            }
        }
        TabButton {
            text: qsTr("Zarejestruj")
            enabled: stack.depth != 2
            onClicked: {
                stack.push(registerView)
            }
        }
    }

    StackView {
        id: stack
        width: 294
        height: 306
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        initialItem: loginView
        Component.onCompleted: stack.pop(loginView)
        Page {
            id: loginView
            Column {
                anchors.fill: parent
                spacing: 8
                TextField {
                    id: lv_l
                    placeholderText: "Login"
                    width: parent.width
                    text: page.loginViewLogin
                }
                TextField {
                    id: lv_h
                    placeholderText: "Hasło"
                    width: parent.width
                    text: page.loginViewPassowrd
                    echoMode: TextInput.Password
                }
                Button {
                    id: loginButton
                    highlighted: true
                    width: parent.width
                    text: "Zaloguj"
                    Timer {
                        id: loginButtonTimer
                        interval: 1500; running: false; repeat: false
                        onTriggered: loginButton.enabled = true
                    }
                    onClicked: {
                        loginButton.enabled = false
                        loginButtonTimer.running = true
                        loginClicked()
                    }
                }
            }
        }
        Page {
            id: registerView
            visible: false
            Column {
                anchors.fill: parent
                spacing: 8
                TextField {
                    id: rv_l
                    placeholderText: "Login"
                    width: parent.width
                    text: page.registerViewLogin
                }
                TextField {
                    id: rv_h
                    placeholderText: "Hasło"
                    width: parent.width
                    text: page.registerViewPassword
                    echoMode: TextInput.Password
                }
                TextField {
                    id: rv_ha
                    placeholderText: "Powtórz hasło"
                    width: parent.width
                    text: page.registerViewPasswordAgain
                    echoMode: TextInput.Password
                }
                Button {
                    highlighted: true
                    width: parent.width
                    text: "Zarejestruj"
                    onClicked: {
                        registerClicked()
                    }
                }
            }
        }
    }

}
