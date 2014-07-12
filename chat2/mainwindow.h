#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "talk/login/status.h"
#include "MVC.h"
#include "./config/rwxml.h"
#include <QMainWindow>
#include "login.h"

class Talkmm;
class BuddyView;
class chat;
class Console;

struct RosterItem
{
    buzz::Jid jid;
    buzz::Status::Show show;
    std::string status;
    bool online;
    bool file_cap;
    bool phone_cap;

};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void set_console(Console* f_console)
    {
        m_console = f_console;
    }

    void on_signon();
    void on_roster_presence(const buzz::Status& status_);
    void on_receive_message(const std::string& from, const std::string& message);
    void on_send_message(const std::string& to, const std::string& message);

    void on_loginWindow_cancel();
    void on_login_error(const std::string& error);

    void on_hangup_call(const std::string& from);
    void on_incoming_call(const std::string& from);

    void on_file_receive(const std::string& from, const std::string& file);
    void on_file_update_progress(const std::string& jid, const std::string& file, float percent, const std::string& describe);
    void on_filetranser_statue(const std::string& jid, const std::string& statue);

    void on_calling_statue(const std::string& jid, const std::string& statue);

private:
    Ui::MainWindow *ui;
    login* m_pLoginW;

    typedef std::map<std::string, RosterItem> RosterMap;
    typedef std::map<std::string, chat*> Session;
    RosterMap* m_roster;
    Talkmm* m_talkmm;
    Console* m_console;
    Session* m_session;

    enum
    {
        LOGIN_INIT = 0,
        LOGIN_LOADING,
        LOGIN_FINISH
    };

    typedef struct {
        QString sUsername;
        QString sPassword;
    }Account;

    Account m_account;
};

#endif // MAINWINDOW_H
