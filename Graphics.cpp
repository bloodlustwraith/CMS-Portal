#include "Graphics.h"
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>
using namespace std;
using namespace sf;



void Graphics::startCMS()
{
	RenderWindow window(VideoMode(1280,720), "CMS", Style::Default);
	RectangleShape CMS(Vector2f(1280, 720));
	Texture picture;
	picture.loadFromFile("cms.jpg");
	CMS.setTexture(&picture);
	double temp = 0;
	while(window.isOpen()) {
		if(temp < 255) {
			temp += 0.3;
			CMS.setFillColor(Color::Color(255, 255, 255, temp));
		}
		if(temp >= 255)
			window.close();
		window.clear();
		window.draw(CMS);
		window.display();
	}
}

void Graphics::endCMS()
{
	RenderWindow window(VideoMode(1280, 720), "ThanK You", Style::Default);
	RectangleShape CMS(Vector2f(1280, 720));
	Texture picture;
	picture.loadFromFile("ThankYou.jpg");
	CMS.setTexture(&picture);
	double temp = 0;
	while(window.isOpen()) {
		if(temp < 255) {
			temp += 0.3;
			CMS.setFillColor(Color::Color(255, 255, 255, temp));
		}
		if(temp >= 255)
			window.close();
		window.clear();
		window.draw(CMS);
		window.display();
	}
}
