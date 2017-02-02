#ifndef WORKSPACE_H
#define WORKSPACE_H


#include <QWidget>
#include <QString>
#include <QFileDialog>
#include <QFileSystemModel>

class Workspace : public QWidget
{
    Q_OBJECT

public:

    explicit Workspace(QWidget *parent = 0);

    void update(); //opens file browser and sets mWorkspacePath to selected folder

    QModelIndex getModelIndex() const
    {
        return mFileSystemModel.index(mWorkspacePath);
    }

    QFileSystemModel mFileSystemModel;

private:

    void update(QString const workspacePath); //sets mWorkspacePath to given path
    void readFromFile(); //read workspace path from the file
    void writeToFile(QString const workspacePath); // write workspace path in to the file

    QString mWorkspacePath;
    static const char * cWorkspaceFileName;
};

#endif // WORKSPACE_H
