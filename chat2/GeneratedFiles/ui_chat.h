/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created: Mon Jul 2 12:27:40 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFontComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chat
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QFontComboBox *fontComboBox;
    QComboBox *fontsizecomboBox;
    QToolButton *textbold;
    QToolButton *textitalic;
    QToolButton *textUnderline;
    QToolButton *textcolor;
    QToolButton *sendfile;
    QToolButton *save;
    QToolButton *clear;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *close;
    QPushButton *send;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;

    void setupUi(QDialog *chat)
    {
        if (chat->objectName().isEmpty())
            chat->setObjectName(QString::fromUtf8("chat"));
        chat->resize(431, 401);
        layoutWidget = new QWidget(chat);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 411, 351));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        textBrowser->setFrameShadow(QFrame::Sunken);
        textBrowser->setOpenExternalLinks(false);

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fontComboBox = new QFontComboBox(layoutWidget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fontComboBox->sizePolicy().hasHeightForWidth());
        fontComboBox->setSizePolicy(sizePolicy1);
        fontComboBox->setMinimumSize(QSize(1, 25));

        horizontalLayout->addWidget(fontComboBox);

        fontsizecomboBox = new QComboBox(layoutWidget);
        fontsizecomboBox->setObjectName(QString::fromUtf8("fontsizecomboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fontsizecomboBox->sizePolicy().hasHeightForWidth());
        fontsizecomboBox->setSizePolicy(sizePolicy2);
        fontsizecomboBox->setMinimumSize(QSize(0, 25));
        fontsizecomboBox->setEditable(true);

        horizontalLayout->addWidget(fontsizecomboBox);

        textbold = new QToolButton(layoutWidget);
        textbold->setObjectName(QString::fromUtf8("textbold"));
        textbold->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/textbold.png"), QSize(), QIcon::Normal, QIcon::Off);
        textbold->setIcon(icon);
        textbold->setIconSize(QSize(24, 24));
        textbold->setCheckable(true);
        textbold->setAutoRaise(true);

        horizontalLayout->addWidget(textbold);

        textitalic = new QToolButton(layoutWidget);
        textitalic->setObjectName(QString::fromUtf8("textitalic"));
        textitalic->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/textitalic.png"), QSize(), QIcon::Normal, QIcon::Off);
        textitalic->setIcon(icon1);
        textitalic->setIconSize(QSize(24, 24));
        textitalic->setCheckable(true);
        textitalic->setAutoRaise(true);

        horizontalLayout->addWidget(textitalic);

        textUnderline = new QToolButton(layoutWidget);
        textUnderline->setObjectName(QString::fromUtf8("textUnderline"));
        textUnderline->setAutoFillBackground(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/textunder.png"), QSize(), QIcon::Normal, QIcon::Off);
        textUnderline->setIcon(icon2);
        textUnderline->setIconSize(QSize(24, 24));
        textUnderline->setCheckable(true);
        textUnderline->setAutoRaise(true);

        horizontalLayout->addWidget(textUnderline);

        textcolor = new QToolButton(layoutWidget);
        textcolor->setObjectName(QString::fromUtf8("textcolor"));
        textcolor->setAutoFillBackground(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/textcolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        textcolor->setIcon(icon3);
        textcolor->setIconSize(QSize(24, 24));
        textcolor->setCheckable(false);
        textcolor->setAutoRaise(true);

        horizontalLayout->addWidget(textcolor);

        sendfile = new QToolButton(layoutWidget);
        sendfile->setObjectName(QString::fromUtf8("sendfile"));
        sendfile->setAutoFillBackground(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendfile->setIcon(icon4);
        sendfile->setIconSize(QSize(24, 24));
        sendfile->setCheckable(false);
        sendfile->setAutoRaise(true);

        horizontalLayout->addWidget(sendfile);

        save = new QToolButton(layoutWidget);
        save->setObjectName(QString::fromUtf8("save"));
        save->setAutoFillBackground(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/Floppy.png"), QSize(), QIcon::Normal, QIcon::Off);
        save->setIcon(icon5);
        save->setIconSize(QSize(24, 24));
        save->setCheckable(false);
        save->setAutoRaise(true);

        horizontalLayout->addWidget(save);

        clear = new QToolButton(layoutWidget);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setAutoFillBackground(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/Bin (empty).png"), QSize(), QIcon::Normal, QIcon::Off);
        clear->setIcon(icon6);
        clear->setIconSize(QSize(24, 24));
        clear->setCheckable(false);
        clear->setAutoRaise(true);

        horizontalLayout->addWidget(clear);


        verticalLayout->addLayout(horizontalLayout);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy3);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        textEdit->setFont(font);

        verticalLayout->addWidget(textEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        close = new QPushButton(layoutWidget);
        close->setObjectName(QString::fromUtf8("close"));
        close->setMinimumSize(QSize(100, 25));

        horizontalLayout_2->addWidget(close);

        send = new QPushButton(layoutWidget);
        send->setObjectName(QString::fromUtf8("send"));
        send->setMinimumSize(QSize(100, 25));

        horizontalLayout_2->addWidget(send);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayoutWidget = new QWidget(chat);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 411, 21));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);


        retranslateUi(chat);

        fontsizecomboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(chat);
    } // setupUi

    void retranslateUi(QDialog *chat)
    {
        chat->setWindowTitle(QApplication::translate("chat", "Dialog", 0, QApplication::UnicodeUTF8));
        fontsizecomboBox->clear();
        fontsizecomboBox->insertItems(0, QStringList()
         << QApplication::translate("chat", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("chat", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("chat", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("chat", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("chat", "13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("chat", "14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("chat", "15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("chat", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("chat", "17", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("chat", "18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("chat", "19", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("chat", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("chat", "21", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("chat", "22", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        textbold->setToolTip(QApplication::translate("chat", "\345\212\240\347\262\227", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        textbold->setText(QApplication::translate("chat", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textitalic->setToolTip(QApplication::translate("chat", "\345\200\276\346\226\234", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        textitalic->setText(QApplication::translate("chat", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textUnderline->setToolTip(QApplication::translate("chat", "\344\270\213\345\210\222\347\272\277", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        textUnderline->setText(QApplication::translate("chat", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textcolor->setToolTip(QApplication::translate("chat", "\345\255\227\344\275\223\351\242\234\350\211\262", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        textcolor->setText(QApplication::translate("chat", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        sendfile->setToolTip(QApplication::translate("chat", "\344\274\240\351\200\201\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        sendfile->setText(QApplication::translate("chat", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        save->setToolTip(QApplication::translate("chat", "\344\277\235\345\255\230\350\201\212\345\244\251\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        save->setText(QApplication::translate("chat", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        clear->setToolTip(QApplication::translate("chat", "\346\270\205\347\251\272\350\201\212\345\244\251\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        clear->setText(QApplication::translate("chat", "...", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("chat", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        close->setText(QApplication::translate("chat", "\345\205\263\351\227\255(&C)", 0, QApplication::UnicodeUTF8));
        send->setText(QApplication::translate("chat", "\345\217\221\351\200\201(&S)", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class chat: public Ui_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
