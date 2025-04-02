#pragma once
#include "astar.hpp"

class rPathingGrid : public rNode {
public:
	AStar::AStar<> pathfinder;

	void setSize(rVector2<unsigned int> _size) {
		pathfinder.setWorldSize({ static_cast<int>(_size.x), static_cast<int>(_size.y) });
	}

	void setDiagonalMovement(bool enable) {
		pathfinder.setDiagonalMovement(enable);
	}

	void set(rVector2<unsigned int> position, bool block) {
		if (block) {
			pathfinder.addObstacle({ static_cast<int>(position.x), static_cast<int>(position.y) });
		}
		else {
			pathfinder.removeObstacle({ static_cast<int>(position.x), static_cast<int>(position.y) });
		}
	}

	rList<rVector2<unsigned int>> getPath(rVector2<unsigned int> startPos, rVector2<unsigned int> endPos) {
		rList<rVector2<unsigned int>> result;

		auto path = pathfinder.findPath({ static_cast<int>(startPos.x), static_cast<int>(startPos.y) }, {static_cast<int>(endPos.x), static_cast<int>(endPos.y)});

		for (auto& point : path) {
			result.add(rVector2<unsigned int>{static_cast<unsigned int>(point.x), static_cast<unsigned int>(point.y)});
		}

		return result;
	}
};