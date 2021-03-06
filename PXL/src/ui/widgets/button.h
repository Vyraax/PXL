#pragma once

#include <string>
#include <iostream>

#include "../core/widget.h"

class Button : public Widget
{
public:
	Button(glm::vec2& position, glm::vec2& size, const std::string& font);
	~Button();

	inline void setBackground(NVGcolor& color) { m_background = color; }
	inline NVGcolor& getBackground() { return m_background; }

	inline void setMargin(const glm::vec4& margin) { m_margin = margin; }
	inline glm::vec4& getMargin() { return m_margin; }

	inline void setText(const std::string& text) { m_text.text = text; }
	inline const std::string getText() { return m_text.text; }

	void update(double delta);
	void draw(NVGcontext* ctx, double delta);
	void drawBackground(NVGcontext* ctx, glm::vec2& position, glm::vec2& size);
	void drawText(NVGcontext* ctx, glm::vec2& position, glm::vec2& size);

	void onKeyDown(const SDL_Event& event);
	void onTextInput(const SDL_Event& event);
	void onKeyUp(const SDL_Event& event);
	void onMouseMove(const SDL_Event& event);
	void onMouseDown(const SDL_Event& event);
	void onMouseUp(const SDL_Event& event);
	void onWindowResized(const SDL_Event& event);
	void onWindowSizeChanged(const SDL_Event& event);


private:
	NVGcolor m_background;
	NVGcolor m_hightlight;

	float m_borderRadius;
	glm::vec4 m_margin;

	struct ButtonText {
		std::string text;
		std::string font;
		NVGalign align;
		NVGcolor color;
		NVGcolor shadow;
		float fontSize;
		float blur;
		float width;
	} m_text;

};
