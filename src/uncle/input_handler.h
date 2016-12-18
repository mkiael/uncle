#pragma once

namespace uncle {

enum class Command;

class InputHandler
{
public:
    InputHandler();

    ~InputHandler();

    Command read_input();

    char get_character() const;

private:
    int m_input;
};

}
