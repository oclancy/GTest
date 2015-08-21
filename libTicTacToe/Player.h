#pragma once
#include "Board.h"
#include "ArtificialIntelligence.h"

class CPlayer
{
protected:
	CPlayer(char token) :_token(token) {};

public:
	virtual ~CPlayer()
	{
	}

	virtual void TakeTurn(CBoard& board) = 0;
	virtual void Learn(int reward)=0;

	char GetToken() const { return _token; };

protected:
	char _token;
};

class CAutoPlayer : public CPlayer
{
public:
	CAutoPlayer(char token, CArtificialIntelligence& ai)
		: CPlayer(token),_ai(ai)
			{}

	void TakeTurn(CBoard& board) override final;
	void Learn(int reward) override final;

private:
	CArtificialIntelligence& _ai;
};



