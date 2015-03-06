﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class DocumentView;
class PropertyView;
class MapEntity;

QT_FORWARD_DECLARE_CLASS(QTreeView)
QT_FORWARD_DECLARE_CLASS(QPrinter)
QT_FORWARD_DECLARE_CLASS(QCloseEvent)

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    DocumentView *currentDocument() const;
public slots:
    void newFile();
    void openFile();
    void openRecentFile();
    bool saveFile();
    bool saveAsFile();
    void autoSave();
    void closeFile();
    void exportFile();
    void printFile();
    void printCurrent();

    void deleteEntity();

    void rebuildTreeView();
    void updatePropertyView(MapEntity* mapEntity);

    void setPolygonTool();
    void setSelectTool();
    void setPubPointTool();
    void setMergeTool();
    void setSplitTool();
    void setScaleTool();
    void setGraphicsViewFont();
protected:
    void closeEvent(QCloseEvent *event);
private:
    bool okToContinue();
    void addDocument(DocumentView* doc);
    void openDocument(const QString & fileName);
    bool saveDocument(const QString & fileName);
    void setCurrentFile(const QString & fileName);
    void readSettings();
    void writeSettings();
    void updateRecentFileActions();

    Ui::MainWindow *ui;

    QTreeView *m_sceneTreeView;
    PropertyView *m_propertyView;
    const int m_maxRecentFiles;
    QStringList m_recentFiles;
    std::vector<QAction*> m_recentFileActions;
    QString m_curFile;
    QString m_lastFilePath;
    DocumentView* m_docView;
    QPrinter *m_printer;
    QTimer *m_timer;
    int m_autoSaveTime;
};

#endif // MAINWINDOW_H
