#include "Engine.hpp"

Engine::Engine(): _state(ENGINE_READY), _playerNumber(0), _aiNumber(0) {

}

void Engine::registerEngineCallback(EngineStateCallback callback, void* context) {
    _callback = callback;
    _context = context;
}

void Engine::begin() {
    if (_state == ENGINE_READY) {
        _state = PLAYER_TURN;
        _callback(PLAYER_TURN, _context);
    }
}

void Engine::playerGetNumber(int num) {
    if (_state == PLAYER_TURN) {
        _playerNumber += num;
        if (_playerNumber > 8) {
            _playerNumber = 8;
        }

        _state = PLAYER_STEP;
        _callback(PLAYER_STEP, _context);
    }
}

void Engine::playerStepFinish() {
    if (_state == PLAYER_STEP) {
        if (_playerNumber == 8) {
            _state = PLAYER_WIN;
            _callback(PLAYER_WIN, _context);
        } else {
            _state = AI_TURN;
            _callback(AI_TURN, _context);
        }
    }
}

void Engine::aiGetNumber(int num) {
    if (_state == AI_TURN) {
        _aiNumber += num;
        if (_aiNumber > 8) {
            _aiNumber = 8;
        }

        _state = AI_STEP;
        _callback(AI_STEP, _context);
    }
}

void Engine::aiStepFinish() {
    if (_state == AI_STEP) {
        if (_aiNumber == 8) {
            _state = AI_WIN;
            _callback(AI_WIN, _context);
        } else {
            _state = PLAYER_TURN;
            _callback(PLAYER_TURN, _context);
        }
    }
}
