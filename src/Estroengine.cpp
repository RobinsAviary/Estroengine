#include "../include/Estroengine.h"
#include <iostream>

List<Node*> garbage;

// GARBAGE DAY. /ref
void Estro::Engine::garbageCollect() {
    for (const Node* piece : garbage) {
        delete piece;
    }

    garbage.clear();
}

void Estro::Engine::step() {
    List<Node*> descendants = getDescendants();

    for (Node* descendant : descendants) {
        descendant->step();
    }
}

void Estro::Engine::draw() {
    List<Node*> descendants = getDescendants();

    for (Node* descendant : descendants) {
        descendant->draw();
    }
}

void Estro::Engine::update() {
    beginStep();
    step();
    endStep();
    beginDraw();
    draw();
    endDraw();
    garbageCollect();
}

void Node::destroy() {
    auto list = getDescendants();
    list.add(this);
    garbage.append(list);
    if (parent) {
        parent->_children.remove(this);
    }
    onDestroy();
}