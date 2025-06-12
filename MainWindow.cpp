#include "MainWindow.h"

#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();

    // Example: connect signals (you'll implement actual logic)
    connect(searchLineEdit, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);
    connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddClicked);
    connect(updateButton, &QPushButton::clicked, this, &MainWindow::onUpdateClicked);
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::onRemoveClicked);

    populateResourceList();
}

void MainWindow::setupUi() {
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    const int margin = 24;
    const int spacing = 16;

    QVBoxLayout *mainLayout = new QVBoxLayout(central);
    mainLayout->setContentsMargins(margin, margin, margin, margin);
    mainLayout->setSpacing(spacing);

    // Search bar
    searchLineEdit = new QLineEdit(central);
    searchLineEdit->setPlaceholderText("Search resources by title...");
    searchLineEdit->setObjectName("searchLineEdit");
    mainLayout->addWidget(searchLineEdit);

    // Resource list
    resourceListWidget = new QListWidget(central);
    resourceListWidget->setObjectName("resourceListWidget");
    mainLayout->addWidget(resourceListWidget);

    // Buttons layout
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    mainLayout->addLayout(buttonLayout);

    addButton = new QPushButton("Add", central);
    addButton->setObjectName("addResourceButton");
    buttonLayout->addWidget(addButton);

    updateButton = new QPushButton("Update", central);
    updateButton->setObjectName("updateResourceButton");
    buttonLayout->addWidget(updateButton);

    removeButton = new QPushButton("Remove", central);
    removeButton->setObjectName("removeResourceButton");
    buttonLayout->addWidget(removeButton);

    // Set window properties
    setWindowTitle("Library Management System");
    resize(800, 600);

    // Apply stylesheet consistent with Default Design Guidelines
    setStyleSheet(R"(
        #searchLineEdit {
            padding: 10px;
            font-size: 14pt;
            border: 1px solid #d1d5db;
            border-radius: 8px;
        }
        #resourceListWidget {
            background: #f9fafb;
            border: 1px solid #e5e7eb;
            border-radius: 12px;
            font-size: 13pt;
            color: #374151;
        }
        QPushButton {
            background-color: #3b82f6;
            color: white;
            padding: 10px 28px;
            border-radius: 12px;
            font-weight: 700;
            font-size: 13pt;
            margin: 0 6px;
            border: none;
        }
        QPushButton:hover {
            background-color: #2563eb;
        }
    )");
}

void MainWindow::populateResourceList() {
    resourceListWidget->clear();

    // Example resource items
    resourceListWidget->addItem("Effective C++");
    resourceListWidget->addItem("Design Patterns");
    resourceListWidget->addItem("Modern Software Engineering");
}

void MainWindow::onSearchTextChanged(const QString &text) {
    // Implement search filtering logic here
    Q_UNUSED(text);
}

void MainWindow::onAddClicked() {
    // Implement add resource logic here
}

void MainWindow::onUpdateClicked() {
    // Implement update resource logic here
}

void MainWindow::onRemoveClicked() {
    // Implement remove resource logic here
}
