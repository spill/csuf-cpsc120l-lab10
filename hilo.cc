// Anthony Vasquez
// CPSC 120-04
// 2022-11-20
// kwortman@fullerton.edu
// @dskoman
//
// Lab 11-02
// Partners: @christianr6 @rtrinh02
//
// Object-oritented hilo game
//

#include "hilo.h"

#include "rng.h"

GameState::GameState(int secret) : secret_(secret), guesses_left_(5){};

int GameState::Secret() const { return secret_; }

int GameState::GuessesLeft() const { return guesses_left_; }

bool GameState::GuessCorrect(int guess) const { return guess == secret_; }

bool GameState::GuessTooBig(int guess) const { return guess > secret_; }

bool GameState::GuessTooSmall(int guess) const { return guess < secret_; }

void GameState::CountGuess() { guesses_left_--; }

bool GameState::GameOver() const { return guesses_left_ == 0; }

int RandomSecretNumber() {
  RandomNumberGenerator rand(0, 10);
  int random_number = int(rand.next());

  return random_number;
}
