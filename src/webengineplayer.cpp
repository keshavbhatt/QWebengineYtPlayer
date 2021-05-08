#include "webengineplayer.h"

#include <QWebEngineView>
#include <QWebEngineSettings>
#include <QWebEngineFullScreenRequest>
#include <QVBoxLayout>

WebEnginePlayer::WebEnginePlayer(QWidget *parent)
    : QWidget(parent)
    , m_view(new QWebEngineView(this))
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_view);
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    m_view->settings()->setAttribute(QWebEngineSettings::FullScreenSupportEnabled, true);
    connect(m_view->page(),
            &QWebEnginePage::fullScreenRequested,
            this,
            &WebEnginePlayer::fullScreenRequested);

    this->reset();
}

void WebEnginePlayer::play(QString vId)
{
    if(vId.trimmed().isEmpty() == false){
        QString urlStr = "https://keshavbhatt.github.io/YtTest/?v=%1";
        m_view->load(QUrl(urlStr.arg(vId)));
    }
}

void WebEnginePlayer::playPlaylist(QString pId)
{
    if(pId.trimmed().isEmpty() == false){
        QString urlStr = "https://keshavbhatt.github.io/YtTest/?p=%1";
        m_view->load(QUrl(urlStr.arg(pId)));
    }
}

void WebEnginePlayer::playAuthorUploads(QString aId)
{
    if(aId.trimmed().isEmpty() == false){
        QString urlStr = "https://keshavbhatt.github.io/YtTest/?u=%1";
        m_view->load(QUrl(urlStr.arg(aId)));
    }
}

void WebEnginePlayer::reset()
{
    m_view->setHtml("<html><head><style type='text/css'>html{overflow: hidden;}"
                    "body{ height: 100%;width: 100%; background-color: black;}"
                    "</style></head><body></body></html>");
}

void WebEnginePlayer::fullScreenRequested(QWebEngineFullScreenRequest request)
{
    if (request.toggleOn()) {
        if (m_fullScreenWindow)
            return;
        request.accept();
        m_fullScreenWindow.reset(new FullScreenWindow(m_view));
    } else {
        if (!m_fullScreenWindow)
            return;
        request.accept();
        m_fullScreenWindow.reset();
    }
}
