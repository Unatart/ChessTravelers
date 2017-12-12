#ifndef CUSTOMSOUND_H
#define CUSTOMSOUND_H

#include <QSound>
#include <QtMultimedia/QMediaPlayer>

#include <memory>

typedef std::string Path;

class CustomSound: public QMediaPlayer {
    private:
        Path soundPath;
        //std::unique_ptr<QMediaPlaylist> playList;

    public:
        CustomSound(Path soundPath);
        CustomSound();
        ~CustomSound();

        QString getSoundPath();
        void setSoundPath(Path pathSound);

        void playInMenu();
        void playInGame();
        void SoundClick();
};

#endif // CUSTOMSOUND_H
