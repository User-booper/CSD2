#include <iostream>
#include "callback.h"

int main() {
    ScopedMessageThreadEnabler scopedMessageThreadEnabler;
    Callback audioSource (44100);
    JUCEModule juceModule (audioSource);
    juceModule.init(1,1);

    std::cout << "Press q + Enter to quit..." << std::endl;
    bool running = true;
    while (running) {
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
        }
    }

    return 0;
}
