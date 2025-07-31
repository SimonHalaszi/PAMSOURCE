#pragma once
#include <raylib.h>
#include "constants.hpp"
#include "colors.hpp"
#include "grid.hpp"

class MakeRectButton {
    public:
        MakeRectButton(const Vector2&);
        void MakeRect(Grid&, const Color&);
        void Toggle();
        bool Inside();
        void Draw();
        
        bool SelectedOnce() const { return (selectionOne.x != -1000); }
        Vector2 GetSelectionOne() const { return selectionOne; }
        bool GetMakingRect() const { return makingRect; }

        void SetSelectionOne(const Vector2& newValue) { selectionOne = newValue; }
        void SetSelectionTwo(const Vector2& newValue) { selectionTwo = newValue; }
        void SetMakingRect(const bool& newValue) { makingRect = newValue; }

    private:
        Vector2 origin;
        Vector2 selectionOne; 
        Vector2 selectionTwo;
        bool makingRect;           
        Font font = GetFontDefault();  
};