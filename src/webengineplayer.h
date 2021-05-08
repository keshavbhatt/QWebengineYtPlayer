#ifndef WEBENGINEPLAYER_H
#define WEBENGINEPLAYER_H

#include "fullscreenwindow.h"

#include <QMainWindow>
#include <QWebEngineView>
#include <QWebEngineFullScreenRequest>

class WebEnginePlayer : public QWidget
{
    Q_OBJECT

public:
    explicit WebEnginePlayer(QWidget *parent = nullptr);

public slots:
    void play(QString vId);
    void reset();
    void playPlaylist(QString pId);
    void playAuthorUploads(QString aId);
private slots:
    void fullScreenRequested(QWebEngineFullScreenRequest request);
private:
    QWebEngineView *m_view = nullptr;
    QScopedPointer<FullScreenWindow> m_fullScreenWindow;
};

#endif // WEBENGINEPLAYER_H
