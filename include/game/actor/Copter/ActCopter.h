#ifndef ACTCOPTER_H
#define ACTCOPTER_H

#include "../include/game/actor/VActor.h"
#include "../include/game/actor/Copter/parts/AirCannon.h"
#include "../include/game/actor/Copter/parts/LiftCup.h"

class CActCopter: public CVActor {
    public:
        CVList field_0x3B4;
        f32 field_0x3C4;
        f32 thrust[2];
        CVVector field_0x3D0;
        CVVector field_0x3DC;
        f32 field_0x3E8;
        f32 roll;
        f32 pitch;
        f32 yaw;
        f32 autoHover_thrust;
        f32 autoHover_drag_f;
        f32 autoHover_drag_tq;
        f32 autoHover_drag_v;
        f32 autoHover_drag_w;
        f32 field_0x40C;
        f32 field_0x410;
        f32 field_0x414;
        f32 stability;
        f32 lift_power;
        f32 rotor_sound_name;
        f32 rotor_sound_pitch;  // Pitch of the rotor SFX when accelerating.
        f32 pitch_gain;
        f32 pitch_area[2];
        f32 pitch_area_range;
        UNK32 field_0x43C;
        UNK32 field_0x440;
        CVVector field_0x444;
        UNK32 field_0x450;
        f32 max_battery_capacity;
        f32 current_battery;
        f32 battery_decrease_rate;
        s32 life;
        s32 durability;
        CAirCannon mAirCannon;
        CLiftCup mLiftCup;
        s32 item;   // Item equipped. 0 = NONE, 1 = Air Cannon, 2 = Lift Cup
        f32 field_0x4C8;
        UNK32 field_0x4CC;
        UNK32 field_0x4D0;
        CVVector field_0x4D4;
        CVVector field_0x4E0;
        UNK32 field_0x4EC;
        CVVector resNodePos_startPos;
        CVVector resNodeRoll_startPos;
        f32 field_0x508;
        f32 field_0x50C;
        f32 field_0x510;
        UNK8 field_0x514[476];

        CActCopter();
        virtual ~CActCopter();
};  // Size = 0x6EC

#endif // ACTCOPTER_H
