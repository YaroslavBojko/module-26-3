#include <iostream>

class Monitor
{
    int monitorWidth = 80;
    int monitorHeight = 50;

    public:
    int matrixPixels [50][80];

    void matrixZeros()
    {
        for (int i = 0; i < monitorHeight; ++i)
        {
            for (int j = 0; j < monitorWidth; ++j)
            {
                matrixPixels[i][j] = 0;
            }
        }
    }

    int getMonitorWidth ()
    {
        return monitorWidth;
    }

    int getMonitorHeight ()
    {
        return monitorHeight;
    }

    int setCoordinatesX(int x)
    {
        if (x < 0) x = 0;
        if (x > monitorWidth) x = monitorWidth;
        return x;
    }

    int setCoordinatesY(int y)
    {
        if (y < 0) y = 0;
        if (y > monitorHeight) y = monitorHeight;
        return y;
    }

    int setWidth(int width)
    {
        if(width <= 0) width = 1;
        if (width > monitorWidth) width = monitorWidth;
        return width;
    }

    int setHeight(int height)
    {
        if(height <= 0) height = 1;
        if (height > monitorHeight) height = monitorHeight;
        return height;
    }
};

class Window
{
    int upperLeftCornerX = 0;
    int upperLeftCornerY = 0;
    int windowWidth = 40;
    int windowHeight = 25;
    Monitor* monitor = new Monitor;

public:
    void move ()
    {
        int x,y;
        std::cout << "Specify window offset vector (X,Y): ";
        std::cin >> x >> y;

        upperLeftCornerX = monitor->setCoordinatesX(x);
        upperLeftCornerY = monitor->setCoordinatesY(y);

        std::cout << "New window coordinates: " << upperLeftCornerX << "," << upperLeftCornerY << std::endl;
    }

    void resize()
    {
        int width,height;
        std::cout << "Enter window width: ";
        std::cin >> width;
        windowWidth = monitor->setWidth(width);

        std::cout << "Enter window height: ";
        std::cin >> height;
        windowHeight = monitor->setHeight(height);

        std::cout << "New window size: width - " << windowWidth << " height - " << windowHeight << std::endl;

    }

    void display()
    {
        monitor->matrixZeros();
        if (upperLeftCornerY + windowHeight > monitor->getMonitorHeight())
            windowHeight = monitor->getMonitorHeight() - upperLeftCornerY;
        if (upperLeftCornerX + windowWidth > monitor->getMonitorWidth())
            windowWidth = monitor->getMonitorWidth() - upperLeftCornerX;

        for (int i = upperLeftCornerY; i < upperLeftCornerY + windowHeight; ++i)
        {
            for (int j = upperLeftCornerX; j < upperLeftCornerX + windowWidth; ++j)
            {
                monitor->matrixPixels[i][j] = 1;
            }
        }

        for (int i = 0; i < monitor->getMonitorHeight(); ++i)
        {
            for (int j = 0; j < monitor->getMonitorWidth(); ++j)
            {
                std::cout << monitor->matrixPixels[i][j];
            }
            std::cout << std::endl;
        }
    }
};


int main() {

    Window* window = new Window;
    std::string command;

    while (command != "close")
    {
        std::cout << "Enter command (move, resize, display, close): ";
        std::cin >> command;

        if (command == "move") window->move();
        if (command == "resize") window->resize();
        if (command == "display") window->display();
    }


    delete window;
}
