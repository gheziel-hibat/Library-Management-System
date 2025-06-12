cmake_minimum_required(VERSION 3.14)

project(LibraryManagementSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets) # or Qt5 if using Qt5

set(SOURCES
    main.cpp
    MainWindow.cpp
    Resource.cpp
    Book.cpp
    Article.cpp
    Thesis.cpp
    DigitalContent.cpp
    User.cpp
    Loan.cpp
    Reservation.cpp
    Notification.cpp
    Event.cpp
    ResourceManager.cpp
    UserManager.cpp
    LoanManager.cpp
    ReservationManager.cpp
    NotificationManager.cpp
    PersistenceManager.cpp
    Logger.cpp
)

set(HEADERS
    MainWindow.h
    Resource.h
    Book.h
    Article.h
    Thesis.h
    DigitalContent.h
    User.h
    Loan.h
    Reservation.h
    Notification.h
    Event.h
    ResourceManager.h
    UserManager.h
    LoanManager.h
    ReservationManager.h
    NotificationManager.h
    PersistenceManager.h
    Logger.h
)

set(FORMS
    MainWindow.ui
    Resource.ui
    Book.ui
    Article.ui
    Thesis.ui
    DigitalContent.ui
    User.ui
    Loan.ui
    Reservation.ui
    Notification.ui
    Event.ui
    ResourceManager.ui
    UserManager.ui
    LoanManager.ui
    ReservationManager.ui
    NotificationManager.ui
    PersistenceManager.ui
    Logger.ui
)

qt_wrap_ui(UI_HEADERS ${FORMS})

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${UI_HEADERS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)