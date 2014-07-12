#include "talkmm.h"
#include "console.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->hide();

    m_pLoginW = new login(this);
    //m_pLoginW->show();
    //onnect(dialog, &m_pLoginW::clicked, this, &MainWindow::Login);
    if(m_pLoginW->exec())
    {
       // m_account.sUsername = m_pLoginW->ui->edit_username->text();
        //m_account.sPassword = m_pLoginW->ui->edit_password->text();
    }
    delete m_pLoginW;
    m_pLoginW = NULL;

    this->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_signon()
{

}

void MainWindow::on_roster_presence(const buzz::Status& status_)
{

}

void MainWindow::on_receive_message(const std::string& from, const std::string& message)
{

}

void MainWindow::on_send_message(const std::string& to, const std::string& message)
{

}

void MainWindow::on_loginWindow_cancel()
{

}

void MainWindow::on_login_error(const std::string& error)
{

}

void MainWindow::on_hangup_call(const std::string& from)
{

}

void MainWindow::on_incoming_call(const std::string& from)
{

}

void MainWindow::on_file_receive(const std::string& from, const std::string& file)
{

}

void MainWindow::on_file_update_progress(const std::string& jid, const std::string& file, float percent, const std::string& describe)
{

}

void MainWindow::on_filetranser_statue(const std::string& jid, const std::string& statue)
{

}

void MainWindow::on_calling_statue(const std::string& jid, const std::string& statue)
{

}
