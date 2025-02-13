//Данный бот использует библиотеку tgBot.cpp
// Инструкция по установке: https://github.com/reo7sp/tgbot-cpp 
// Инструкция по библиотеке: http://reo7sp.github.io/tgbot-cpp/
#include <stdio.h>
#include <tgbot/tgbot.h>

int main() {
    TgBot::Bot bot("PLACE YOUR TOKEN");
    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi!");
    });

    // Изучаем http://reo7sp.github.io/tgbot-cpp/, господа...

    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
    return 0;
}
