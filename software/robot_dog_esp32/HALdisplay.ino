double displayHALMovement = 1;  // mm
double displayHALRotation = M_PI/180;

// TODO too much copy-paste!!!

void displayHALMoveBodyX() {
  displayHALMoveBody(XAXIS);
}

void displayHALMoveBodyY() {
  displayHALMoveBody(YAXIS);
}

void displayHALMoveBodyZ() {
  displayHALMoveBody(ZAXIS);
}

void displayHALButtonsBody(int axis) {
  // TODO  pitch/roll/yaw
  if (BUTTON_STATE[BUTTON_UP]) {
    switch (axis) {
      case XAXIS:
        body.position.x = body.position.x + displayHALMovement;
        break;
    case YAXIS:
        body.position.y = body.position.y + displayHALMovement;
        break;
    case ZAXIS:
        body.position.z = body.position.z + displayHALMovement;
        break;
    }
  } else if (BUTTON_STATE[BUTTON_DOWN]) {
    switch (axis) {
      case XAXIS:
        body.position.x = body.position.x - displayHALMovement;
        break;
      case YAXIS:
        body.position.y = body.position.y - displayHALMovement;
        break;
      case ZAXIS:
        body.position.z = body.position.z - displayHALMovement;
        break;
    }
  }
}

void displayHALMoveBody(int axis) {
  displayReset();
  displayHALButtonsBody(axis);
  display.print("Move by ");
  switch (axis) {
    case XAXIS:
      display.print("X");
      break;
    case YAXIS:
      display.print("Y");
      break;
    case ZAXIS:
      display.print("Z");
      break;
    default:
      menuBack(); // something wrong, goes back to menu
      break;
  }
  display.println(" axis");
  
  if (axis == XAXIS) displayHighlightBegin();
  display.print("X: ");
  display.println(body.position.x, DISPLAY_DIGITS);
  displayHighlightEnd();
  
  if (axis == YAXIS) displayHighlightBegin();
  display.print("Y: ");
  display.println(body.position.y, DISPLAY_DIGITS);
  displayHighlightEnd();
  
  if (axis == ZAXIS) displayHighlightBegin();
  display.print("Z: ");
  display.println(body.position.z, DISPLAY_DIGITS);
  displayHighlightEnd();


  display.print("LF ");
  display.print(displayAngle(legs[LEGLF].angle.alpha), 0);
  display.print(" ");
  display.print(displayAngle(legs[LEGLF].angle.beta), 0);
  display.print(" ");
  display.println(displayAngle(legs[LEGLF].angle.gamma), 0);

  display.print("RF ");
  display.print(displayAngle(legs[LEGRF].angle.alpha), 0);
  display.print(" ");
  display.print(displayAngle(legs[LEGRF].angle.beta), 0);
  display.print(" ");
  display.println(displayAngle(legs[LEGRF].angle.gamma), 0);

  display.print("LB ");
  display.print(displayAngle(legs[LEGLB].angle.alpha), 0);
  display.print(" ");
  display.print(displayAngle(legs[LEGLB].angle.beta), 0);
  display.print(" ");
  display.println(displayAngle(legs[LEGLB].angle.gamma), 0);

  display.print("RB ");
  display.print(displayAngle(legs[LEGRB].angle.alpha), 0);
  display.print(" ");
  display.print(displayAngle(legs[LEGRB].angle.beta), 0);
  display.print(" ");
  display.println(displayAngle(legs[LEGRB].angle.gamma), 0);

}