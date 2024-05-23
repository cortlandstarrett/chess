xtUML chess project
===================

This project provides a framework for creating bots to play chess on
[lichess.org](https://lichess.org). The project provides bindings to the
Lichess public API as well as management of challenges and games and a utility
for listing legal moves. The project is set up to run in BridgePoint Model
Verifier.


## Prerequisites

### Download BridgePoint

Download the latest version of BridgePoint from
[here](https://s3.amazonaws.com/xtuml-releases/12804-build/buildfiles.html).
Due to ongoing development related to this project, an engineering branch build
is required to run the project.

### Create a Lichess bot account

To get started, you must create an account on lichess.org. In accordance with
Lichess [terms of service](https://lichess.org/terms-of-service), an account
must _not_ have played any games before being converted to a bot account. The
first time you run the application, your account will automatically be upgraded
to a bot account. Note that you will not be able to use a bot account to play
normally on the site after it has been upgraded. We recommend that you create
two accounts -- one for the bot and one to play as a human player.

1. Create a Lichess account for your bot [here](https://lichess.org/signup).
2. Once logged in, follow [this
   link](https://lichess.org/account/oauth/token/create?scopes[]=bot:play&scopes[]=challenge:write) to
   generate an API token for your bot. Save the token in a secure location.
   Do not commit it to the repository.

### Fork and clone the repository

1. If you intend to contribute code or documentation to the project,
   [fork](doc/img/fork.png "fork") this repository.
2. [Clone](doc/img/clone.png "clone") (your fork of) this repository.

### Maven

Install [Apache Maven](https://maven.apache.org/index.html) either through your
operating system package manager or by downloading the latest release
[here](https://maven.apache.org/users/index.html)


## Running the Application

### Configuration

1. Copy `lichess_bot/src/main/resources/lichess_bot.properties.template` to
   `lichess_bot/src/main/resources/lichess_bot.properties`
2. Edit this file and replace `<YOUR_LICHESS_ACCESS_TOKEN>` with your API token
   that you generated earlier.

### With xtUML Verifier

1. Open BridgePoint on a fresh workspace. Import all the projects from the root
   of the repository.
2. Build the workspace by either clicking "Build All" in the "Project" menu, or by enabling "Build Automatically".
3. Switch to the xtUML Debugging perspective.
4. Select "Run" > "Debug Configurations..." and click on "LichessBot" under the
   "xtUML eXecute Application" heading.
5. Click "Debug" to launch the application.
6. Log in to your human account on lichess.com.
7. Use the [search bar](doc/img/search_opponent.png "search opponent") to navigate
   to the user page for your bot.
8. Challenge your bot to a match (by clicking on the [crossed swords](doc/img/challenge.png "challenge")).

### With Ciera

1. Open a terminal and navigate to the root of the repository.
2. Run the command `mvn install`
3. Return to BridgePoint and open the Java perspective.
4. Select "Run" > "Run Configurations..." and click on "LichessBotJava" under the
   "Java Application" heading.
5. Click "Run" to launch the application.


## Adding bot intelligence

The template project provides the minimum amount of intelligence to play a
game. On its turn, the bot will select a random move from the list of legal
moves and play that move. It is the task of the modeler to improve this
behavior to create a winning strategy.

### Interfaces

The `chess` interface provides a modeled hook into the lichess.org public API.
For more information on this API, visit the Lichess documentation page
[here](https://lichess.org/api). Messages and types were modeled to closely
follow this reference.

### Utilities

The `ChessLib` utility has been provided with the `legalMoves` bridge. This
bridge takes as input an array of moves that have occurred in the game since
the start position. It returns an array of legal moves.

_This section is a work in progress_

### Move representation

Each move is represented by a 4 character string in [Long Algebraic
Notation](https://en.wikipedia.org/wiki/Algebraic_notation_(chess)#Long_algebraic_notation)
-- a four character string in which the first two characters represent the file
(column) and rank (row) on which the moved piece started and the last two
characters represent the file and rank on which the moved piece completed its
move. In standard chess vocabulary, a _move_ represents a move by white and a
corresponding response by black. In the model, however, each move by black _or_
white is represented as its own element in the array of moves representing the
state of the game. A natural consequence of this fact is that if the length of
the move array is divisible by 2, it is white's turn to play. If the array is
not divisible by 2, it is black's turn to play.

### Extending the application

The application consists of two components -- `Engine` and `Lichess`. The
`Lichess` component is a realized component and should not be edited by the
modeler.

The modeler has freedom to extend the application as desired. A natural
starting place is the "our turn" state within the `Game` instance state machine
in the `Engine` component. Here the bot must select the next move and then
generate the "play move" event.

### Chess rules and strategy

lichess.org requires bots to play according to standard chess rules. The moves
returned by the `ChessLib` EE will also observe the rules and only return legal
moves. Any move selected by a bot to play next should be one of these legal
moves.

An excellent resource for learning the rules and some basic bot strategies is
the Chess Programming Wiki found
[here](https://www.chessprogramming.org/Main_Page). The official rules of chess
can be found [here](https://www.fide.com/FIDE/handbook/LawsOfChess.pdf).


## Issues

If you are having an issue with BridgePoint or Verifier,
please check the [issue tracker](https://support.onefact.net) to see if the
behavior matches an existing issue. [This custom
query](https://support.onefact.net/projects/bridgepoint/issues?query_id=169)
has been created to track issues specifically relating to this modeling
challenge. If you don't find the issue you are looking for, please raise a new
issue [here](https://support.onefact.net/projects/bridgepoint/issues/new).

If you have an issue (bug, new feature, etc) with the xtuml/chess project itself,
raise an issue in the [repository tracker](https://github.com/xtuml/chess/issues).
Of course pull requests with fixes and improvements are welcome!

