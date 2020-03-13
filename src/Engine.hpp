#ifndef ENGINE_H
#define ENGINE_H

typedef enum _EngineState {
    ENGINE_READY,
    PLAYER_TURN,
    PLAYER_STEP,
    PLAYER_WIN,
    AI_TURN,
    AI_STEP,
    AI_WIN
} EngineState;

typedef void (*EngineStateCallback)(EngineState, void* context);

class Engine {
private:
    EngineState _state;
    EngineStateCallback _callback;
    void* _context;

    int _playerNumber;
    int _aiNumber;

public:
    Engine();
    void registerEngineCallback(EngineStateCallback callback, void* context);

    void begin();
    void playerGetNumber(int num);
    void playerStepFinish();
    void aiGetNumber(int num);
    void aiStepFinish();
};

#endif
