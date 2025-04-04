// Estroextras!
#pragma once
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include "estrocolors.hpp"
#include <functional>
#include <vector>

class rColorBackground : public rNode {
	public:
		rColor color = cBlack;

		void draw() {
			rDrawClear(color);
		}
};

float deg2rad(float deg) {
    return static_cast<float>(deg * (M_PI / 180));
}

float lengthdir_x(float length, float dir) {
    return (sin(deg2rad(dir)) * length);
}

float lengthdir_y(float length, float dir) {
    return (tan(deg2rad(dir)) * length);
}

float lengthdir_z(float length, float dir) {
    return (cos(deg2rad(dir - 180)) * length);
}

// From https://stackoverflow.com/questions/1903954/is-there-a-standard-sign-function-signum-sgn-in-c-c
template <typename T> int sign(T val) {
    return (T(0) < val) - (val < T(0));
}

/*class FreeCam : public rNode {
public:
    Camera3D camera = { { 0.0f, 10.0f, 0.0f }, { 0.0f, 10.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 92.0f, CAMERA_PERSPECTIVE };

    Vector2 rotation;

    float mouseSensitivity = .8;

    float moveSpeed = 16;

    void step() {
        float delta = GetFrameTime();

        if (IsKeyDown(KEY_W)) {
            camera.position.x += lengthdir_x(moveSpeed * delta, rotation.x);
            camera.position.z += lengthdir_z(moveSpeed * delta, rotation.x);
        }

        if (IsKeyDown(KEY_A)) {
            camera.position.x += lengthdir_x(moveSpeed * delta, rotation.x - 90);
            camera.position.z += lengthdir_z(moveSpeed * delta, rotation.x - 90);
        }

        if (IsKeyDown(KEY_S)) {
            camera.position.x += lengthdir_x(moveSpeed * delta, rotation.x + 180);
            camera.position.z += lengthdir_z(moveSpeed * delta, rotation.x + 180);
        }

        if (IsKeyDown(KEY_D)) {
            camera.position.x += lengthdir_x(moveSpeed * delta, rotation.x + 90);
            camera.position.z += lengthdir_z(moveSpeed * delta, rotation.x + 90);
        }

        if (IsKeyDown(KEY_Q)) {
            camera.position.y -= moveSpeed * delta;
        }

        if (IsKeyDown(KEY_E)) {
            camera.position.y += moveSpeed * delta;
        }
        if (IsWindowFocused()) {
            updateRotation();
        }

        //std::cout << camera.position.x << ", " << camera.position.y << ", " << camera.position.z << std::endl;
    }

    void draw() {
        BeginMode3D(camera);
    }
private:
    void updateRotation() {
        int xMove = GetMouseX() - GetScreenWidth() / 2;
        int yMove = GetMouseY() - GetScreenHeight() / 2;

        //std::cout << "x: " << xMove << " y: " << yMove << std::endl;

        rotation.x += xMove * mouseSensitivity;
        rotation.y -= yMove * mouseSensitivity;

        //rotation.y = Clamp(rotation.y, -89.99999, 89.99999);

        camera.target = Vector3{ camera.position.x + lengthdir_x(1, rotation.x), camera.position.y + lengthdir_y(1, rotation.y), camera.position.z + lengthdir_z(1, rotation.x) };

        SetMousePosition(GetScreenWidth() / 2, GetScreenHeight() / 2);
    }
};*/

class rTimer : public rNode {
public:
    void init(float _seconds, bool startActive = false, bool _looping = false) {
        seconds = _seconds;

        if (startActive) {
            reset();
        }

        looping = _looping;
    }

    void setLength(float _seconds) {
        seconds = _seconds;
    }

    float getLength() {
        return seconds;
    }

    float setTimeLeft(float _seconds) {
        asleep = false;
        finished = false;
        timeLeft = _seconds;
    }

    float getTimeLeft() {
        return timeLeft;
    }

    float getPercentage() {
        return timeLeft / seconds;
    }

    bool isJustFinished() {
        return justFinished;
    }

    bool isFinished() {
        return finished;
    }

    void setLooping(bool _looping) {
        looping = _looping;
    }

    bool getLooping() {
        return looping;
    }

    void reset() {
        timeLeft = seconds;
        asleep = false;
        finished = false;

        if (onReset) {
            onReset();
        }
    }

    void step() {
        if (justFinished) {
            justFinished = false;

            if (looping) reset();
        }

        if (!asleep) {
            timeLeft -= rGetDelta();

            if (timeLeft <= 0) {
                asleep = true;

                justFinished = true;
                finished = true;

                if (onFinished) {
                    onFinished();
                }
            }
        }
    }

    std::function<void()> onFinished;
    std::function<void()> onReset;

private:
    float timeLeft = 0;
    float seconds = 0;
    bool asleep = false;
    bool looping = false;

    bool justFinished = false;
    bool finished = false;
};

/*class rLineRenderer : public rNodeBase {
    public:
	    rColor color;
	
	    void draw() {
		    int pointsSize = points.size();
		    if (pointsSize > 1) {
			    for (int i = 1; i < pointsSize; i++) {
				    rDrawLine(points[i-1].position, points[i].position, color);
			    }
		    }
	    }

        void addPoint(rVector2 position, rColor color) {
            points.push_back(Point{ position, color });
        }

        void insertPoint(int index, rVector2 position, rColor color) {
            points.insert(index, Point{ position, color });
        }

        void removePoint(int index) {
            points.erase(index);
        }

        void setPointPosition(int index, rVector2 position) {
            points[index].position = position;
        }

        rVector2 getPointPosition(int index) {
            return points[index].position;
        }

        void setPointColor(int index, rColor color) {
            points[index].color = color;
        }

        rColor getPointColor(int index) {
            return points[index].color;
        }
    private:
        typedef struct Point {
            rVector2 position,
            rColor color
        } Point;

        std::vector<Point> points;
};*/

/*template <typename T>
class rGrid {
    public:
        void setSize(rVector2 _size) {
            data.clear();
            data.resize(_size.x * _size.y);
            
            size = _size;
        }

        rVector2 getSize() {
            return size;
        }

        T at(rVector2 position) {
            int index = getIndex(position);

            return data[index];
        }

        T set(rVector2 position, T value) {
            int index = getIndex(position);

            data[index] = value;
        }

    private:
        std::vector<T> data;

        rVector2 size = { 0, 0 };

        rVector2 getIndex(rVector2 position) {
            return (position.y * size.y) + position.x;
        }
};*/

class rSprite : public rNode2D {
public:


private:

};

class rSpriteCursor : public rNode {
public:
    rTexture texture;

    rSpriteCursor() {
        rHideCursor();
    }

    ~rSpriteCursor() {
        rShowCursor();
    }

    void draw() {
        if (rIsCursorOnScreen()) {
            rDrawTexture(&texture, rGetMousePosition().cast<float>(), cWhite);
        }
    }
};