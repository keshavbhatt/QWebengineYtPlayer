# QWebengineYtPlayer
Fully functional QWebengineView based YouTube player widget utilizing [YouTube Iframe embed API](https://developers.google.com/youtube/iframe_api_reference)  to create an iframe whose source is hosted [here](https://github.com/keshavbhatt/YtTest). 

> Why we need to host the code ?

YouTube Iframe embed API do not allow playback of some content if the page is hosted locally. 


## Features

 1. Support playback of all quality
 2. Fullscreen support
 3. Playlist Playback
 4. User uploads playback
 5. Video playback

## Requirements
You need Qt 5.6 or above with `webengine` and `webenginewidgets` modules to use this widget in your application.

## How to use in your Qt Project
Go to your project's source directory, clone the repository to `WebEnginePlayer` directory. (You can remove unwanted files likes images etc once done)

    git clone https://github.com/keshavbhatt/QWebengineYtPlayer.git WebEnginePlayer 

Add these two modules (`webengine` and `webenginewidgets` ) to your .pro file. Add the .pri file in your project's .pro file like below.

     include(WebEnginePlayer/src/WebEnginePlayer.pri)
In your code initialize the Widget like this:

    WebEnginePlayer *webenginePlayerWidget  =  new  WebEnginePlayer(this);

To play a YouTube video:

    webenginePlayerWidget->play(videoId);
To play a YouTube playlist:

    webenginePlayerWidget->playPlaylist(plsylistId);
To play a YouTube user's uploads:

    webenginePlayerWidget->playAuthorUploads(authorId);

## Screenshots
![Screenshot showing the widget being use in one of my application Playlist-Dl](https://github.com/keshavbhatt/QWebengineYtPlayer/blob/main/images/1.png?raw=true)
Screenshot showing the widget being use in one of my application [Playlist-Dl](https://snapcraft.io/playlist-dl) (A full featured YouTube playlist search/download application written in Qt)

