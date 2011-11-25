/**
 * Example used in programming courses at University of Parma, IT.
 * Author: Michele Tomaiuolo - <tomamic@ce.unipr.it> - 2009
 *
 * This software is free: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License, version 3 or
 * later. See <http://www.gnu.org/licenses/>.
 */

#include "loader.h"

#include "game.h"
#include "ghost.h"
#include "ice.h"
#include "penguin.h"

#include <sstream>
#include <QtCore/QFile>

using namespace std;

Loader::Loader(string name)
{
    this->name = name;
}

Game* Loader::loadGame(int level)
{
    QFile file(QString("%1-%2.dat").arg(name.c_str()).arg(level));
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    istringstream in(file.readAll().data());

    int h, w, y, x;
    char type;

    in >> h >> w;
    Game* game = new Game(h, w);

    in >> type >> y >> x;
    while (in.good()) {
        if (type == Ghost::SYMBOL) {
            new Ghost(game, y, x);
        } else if (type == Ice::SYMBOL) {
            new Ice(game, y, x);
        } else if (type == Penguin::SYMBOL) {
            new Penguin(game, y, x);
        }
        in >> type >> y >> x;
    }
    return game;
}
