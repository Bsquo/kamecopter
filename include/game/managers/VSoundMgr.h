#ifndef VSOUNDMGR_H
#define VSOUNDMGR_H

#include "../include/game/sound/VSoundGroup.h"
#include "../include/nw4r/snd/snd_DvdSoundArchive.h"
#include "../include/nw4r/snd/snd_SoundArchivePlayer.h"
#include "../include/nw4r/snd/snd_SoundHeap.h"
#include <kamek.h>

class CVSoundMgr {
    protected:
        CVSoundMgr();

    public:
        nw4r::snd::DvdSoundArchive mDvdSoundArchive;
        nw4r::snd::SoundArchivePlayer mSoundArchivePlayer;
        nw4r::snd::SoundHeap mSoundHeap;
        CVSoundGroup mSoundGroups[8];

        static CVSoundMgr* GetInstance();
        virtual ~CVSoundMgr();
        void Release();
        void Init();
        void InitArchive(char*);
        void ReleaseHeap();
        void LoadGroup(char*);
        void StartSound(int, int, int, int);
        void StartSound(char*, int, int, int);
        void HoldSound(char*, int, int);
        void SetMasterVolume(f32, int);
        void SetVolume(int, f32);
        void SetVolume(int, int, f32);
        void SetPitch(int, f32);
        void SetOutPutMode(int);
        void StopSound(int, int, int);
        void PauseSound(int, int, int, int);
        void StopSoundAll(int);
        void PauseSoundAll(int, int);
        void ClearEffectAll(int);
        void Update();
};

#endif // VSOUNDMGR_H