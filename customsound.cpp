#include "customsound.h"
#include <iostream>

CustomSound::CustomSound(Path soundPath):
    soundPath(soundPath)
    //playList(new QMediaPlaylist())
{
    setVolume(80);
    //setPlaylist(playList);
}
CustomSound::CustomSound(): soundPath("") {
    setVolume(80);
}
CustomSound::~CustomSound() { }

QString CustomSound::getSoundPath() {
    return QString::fromStdString(soundPath);
}

void CustomSound::setSoundPath(std::string PathSound) {
    soundPath = PathSound;
}

void CustomSound::playInMenu() {
    //playList->addMedia(QUrl(QString::fromStdString(soundPath) + "menu/background"));
    stop();
    setMedia(QUrl::fromLocalFile(QString::fromStdString(soundPath) + "menu/background.wav"));
    //playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    play();
}

void CustomSound::playInGame() {
    stop();
    setMedia(QUrl::fromLocalFile(QString::fromStdString(soundPath) + "game/background.mp3"));
    play();
}

void CustomSound::SoundClick() {
    QSound::play(QString::fromStdString(soundPath) + "click/click.wav");
}
