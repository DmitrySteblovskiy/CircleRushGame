#pragma once

#include "GeomMaster.h"
#include "Engine.h"
#include "FoodSq.h"
#include "KillingSquare.h"
#include "Square.h"

#include <chrono>
#include <stdint.h>
#include <time.h>

class Dispatcher {
private:
	float cooldown_ = 1;
	float timeSinceLastSpawn_ = 0;

	PlayerCircles* player_;

	Square* FigBegin_ = nullptr;
	Square* FigEnd_ = nullptr;
public:
	Dispatcher(PlayerCircles* plr)	{
		srand(time(0));
		player_ = plr;
	}

	void Draw() {
		Square* iter = FigBegin_;
		while (iter != NULL) {
			iter->Draw();
			iter = iter->next;
		}
	}

	void SpawnSquare(float dt) {
		Square* sq = nullptr;
		if (rand() % 2 == 1) {
			sq = new FoodSq();
		}
		else {
			sq = new KillingSquare();
		}

		if (FigBegin_ == nullptr) {
			FigBegin_ = FigEnd_ = sq;
		}
		else {
			FigEnd_->next = sq;
			sq->prev = FigEnd_;
			FigEnd_ = sq;
		}
			
		timeSinceLastSpawn_ = 0;
	}


	void SqUpd(float dt) {
		Square* beg = FigBegin_;
		while (beg != nullptr) {
			beg->UpdateState(dt);

			if (beg->CheckCollision(player_)) {
				if (beg == FigBegin_ && beg == FigEnd_) {
					FigBegin_ = FigEnd_ = beg = nullptr;
				}
				else if (beg == FigBegin_) {
					FigBegin_ = beg->next;
					free(beg);
					beg = FigBegin_;
				}
				else if (beg == FigEnd_) {
					FigEnd_ = beg->prev;
					free(beg);
					FigEnd_->next = beg = nullptr;
				}
				else {
					beg->prev->next = beg->next;
					beg->next->prev = beg->prev;
					Square* mem = beg;
					beg = beg->next;
					free(mem);
				}
			}
			else {
				beg = beg->next;
			}
		}
	}

	void Update(float dt) {
		timeSinceLastSpawn_ += dt;
		cooldown_ *= 1 - dt / 100;
		if (timeSinceLastSpawn_ >= cooldown_) {
			SpawnSquare(dt);
		}

		SqUpd(dt);
	}
	
	void EndSpiel() {
		std::chrono::milliseconds timespan(1000); // or whatever
		std::this_thread::sleep_for(timespan);
	}
};

