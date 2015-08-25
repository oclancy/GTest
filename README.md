# repo19
*********************************Original Brief*********************************

Here is the coding exercise:
Your task is to create an agent that learns to play a game of tic-tac-toe. It's up to you to decide the training method: 

*implementing a teacher that knows the optimal strategy

*bootstrapping two random agents against themselves

*train the agent yourself 

and store its state for us to load
or any other approach. 

However the trained agent should learn the value or action-value function or policy for each state purely from game play, rather than from knowing the rules and heuristics of the game. Code should be written in C++ or Python.  If you prefer to use a different language, please check with us first.

Use Q-learning and Sarsa to solve the problem. Plot a reward per episode graph for both algorithms. 

SARSA http://webdocs.cs.ualberta.ca/~sutton/book/ebook/node64.html 
Q-learning http://webdocs.cs.ualberta.ca/~sutton/book/ebook/node65.html

We will assign high weight to good code documentation and style. Please include unit tests in your project. Only spare time should be spent on presentation of game play, text output to terminal is sufficient. Also we expect the agent to be pretty good at the game.

Let me know if you have any questions.

*********************************Original Brief*********************************

*********************************Solution**********************************
Running the code:

The solution was developed using MS Visual Studio 2015. I believe GCC will have no problems compiling the source. I had designs to provide a Linux solution but ran out of time. Any recent compiler shouldn't have a problem.
The solution has no other dependencies outside of the Standard Library
The tests use MSTest. I would have liked to have used gtest but ran out of time.

Class AIs:
CRandomGuesser - A dumb AI class interface implementation that randomly chooses a square fromthe available squares
CQLearningIntelligence - An AI implementing the Q-Learning algorithm
CSasaIntelligence - An AI implementing the SARSA algorithm

To run the solution:
1)start the executable. You are presented with 2 options Train, Play (and Exit)
2)Train an AI by selecting option 1 (Train)
	a) select the ai for player 1
	b) select the ai for player 2
	c) enter number of iterations
	d) after the training run completes you have the option to save the training dtaa for each ai
	e) after the option to save the training data there an option to save the average reward data which can be used to plot a chart of average reward vs episodes(1000s)
	The output files for steps d) and e) are saved relative to the executable directory.
3)Play against an AI by selecting option 2 (Play)
	a) select the type of AI you wish to play.
	b) load the training data for the AI saved in step 2) - N.B the formats are different for each AI so care should be taken to select the correct file
	c) play one game of noughts and crosses.



All feedback is welcomed.
*********************************Solution**********************************	
