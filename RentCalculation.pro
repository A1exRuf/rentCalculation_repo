QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculationmethodchoicewindow.cpp \
    calculations.cpp \
    main.cpp \
    mainwindow.cpp \
    menuwindow.cpp \
    methodareawindow.cpp \
    methodfixedtariffs.cpp \
    methodnormatives.cpp \
    methodtenantcount.cpp \
    normativesettingwindow.cpp \
    paymentaccountingwindow.cpp \
    paymenttablewindow.cpp \
    registrationwindow.cpp \
    usersettingwindow.cpp

HEADERS += \
    calculationmethodchoicewindow.h \
    calculations.h \
    mainwindow.h \
    menuwindow.h \
    methodareawindow.h \
    methodfixedtariffs.h \
    methodnormatives.h \
    methodtenantcount.h \
    normativesettingwindow.h \
    paymentaccountingwindow.h \
    paymenttablewindow.h \
    registrationwindow.h \
    usersettingwindow.h

FORMS += \
    calculationmethodchoicewindow.ui \
    mainwindow.ui \
    menuwindow.ui \
    methodareawindow.ui \
    methodfixedtariffs.ui \
    methodnormatives.ui \
    methodtenantcount.ui \
    normativesettingwindow.ui \
    paymentaccountingwindow.ui \
    paymenttablewindow.ui \
    registrationwindow.ui \
    usersettingwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
