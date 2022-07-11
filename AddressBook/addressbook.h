#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include <QRegularExpression>

#include "finddialog.h"

enum Mode { NavigationMode, AddingMode, EditingMode };

class AddressBook : public QWidget
{
    Q_OBJECT
public:
    AddressBook(QWidget *parent = nullptr);

public slots:
    void addContact();
    void submitContact();
    void cancel();
    void next();
    void previous();
    void editContact();
    void removeContact();
    void updateInterface(Mode mode);
    void findContact();
    void saveToFile();
    void loadFromFile();
    void exportAsVCard();

private:
    QLineEdit *nameLine;
    QTextEdit *addressText;
    QPushButton *nextButton;
    QPushButton *previousButton;
    QPushButton *addButton;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QPushButton *editButton;
    QPushButton *removeButton;
    QPushButton *findButton;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QPushButton *exportButton;

    QMap<QString, QString> contacts={{"LIU","BEIJING"},{"YAO","QINHUANGDAO"},{"HAO","TOKYO"},{"SEN","BEIJING"}};
    QString oldName;
    QString oldAddress;
    Mode currentMode;
    FindDialog *dialog;

};

#endif // ADDRESSBOOK_H
