QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SocialMediaApp.cpp \
    createpost.cpp \
    friendlist.cpp \
    home.cpp \
    likedpages.cpp \
    login.cpp \
    main.cpp \
    memories.cpp \
    menu.cpp \
    pagetimeline.cpp \
    post.cpp \
    project.cpp \
    shareMemory.cpp \
    timeline.cpp

HEADERS += \
    SocialMediaApp.h \
    createpost.h \
    friendlist.h \
    home.h \
    likedpages.h \
    login.h \
    memories.h \
    menu.h \
    pagetimeline.h \
    post.h \
    project.h \
    shareMemory.h \
    timeline.h

FORMS += \
    createpost.ui \
    friendlist.ui \
    home.ui \
    likedpages.ui \
    login.ui \
    memories.ui \
    menu.ui \
    pagetimeline.ui \
    post.ui \
    project.ui     \
    sharememory.ui \
    timeline.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Friends.txt \
    LikedPages.txt \
    Pages.txt \
    PagesPosts.txt \
    Users.txt \
    UsersPosts.txt
