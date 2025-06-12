#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

class QListWidget;
class QLineEdit;
class QPushButton;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

private slots:
    void onSearchTextChanged(const QString &text);
    void onAddClicked();
    void onUpdateClicked();
    void onRemoveClicked();

private:
    void setupUi();
    void populateResourceList(); // Example method for demo

    QLineEdit *searchLineEdit;
    QListWidget *resourceListWidget;
    QPushButton *addButton;
    QPushButton *updateButton;
    QPushButton *removeButton;
};

#endif // MAINWINDOW_H
