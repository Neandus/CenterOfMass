#include "workspace.h"
#include <QtCore/QFile>
#include <QMessageBox>
#include <QTextStream>

const char * Workspace::cWorkspaceFileName = ".workspace";

Workspace::Workspace(QWidget *parent)
  : QWidget(parent)
  , mFileSystemModel()
  , mWorkspacePath(QDir::currentPath())
{
    update(mWorkspacePath);
}


void Workspace::update()
{
    QString chosenPath = QFileDialog::getExistingDirectory(this, tr("Choose workspace folder"),
                                                           mWorkspacePath,
                                                           QFileDialog::ShowDirsOnly
                                                           | QFileDialog::DontResolveSymlinks);
    this->writeToFile(chosenPath);
}

void Workspace::update(QString const workspacePath)
{
    if(mWorkspacePath != workspacePath)
        mWorkspacePath = workspacePath;
    mFileSystemModel.setRootPath(mWorkspacePath);
}

void Workspace::readFromFile()
{
    QFile workspaceFile(Workspace::cWorkspaceFileName);

    if(!workspaceFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(0, "Warning", "Workspace file has not been found! Workspace set to defualt path.");

        writeToFile(QDir::currentPath());
    }
    else
    {
        //read workspace path
        QTextStream in(&workspaceFile);
        if(!in.atEnd()) {
            QString path = in.readLine();
            //TODO validate path
            update(path);
        }
    }
    workspaceFile.close();
}

void Workspace::writeToFile(QString const workspacePath)
{
    QFile workspaceFile(Workspace::cWorkspaceFileName);
    if(!workspaceFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox::warning(0, "Error", "Workspace file couldn't be created!");
    }
    else
    {
        QTextStream out(&workspaceFile);
        out << workspacePath << endl;
        workspaceFile.resize(workspaceFile.pos());
        update(workspacePath);
    }
    workspaceFile.close();
}
