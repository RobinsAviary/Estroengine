#pragma once

// These functions exist to allow backends to do things that Estroengine expects at the times they need to be done. To be less abstract, it's used to set up polling events and other stuff that Estroengine doesn't account for by default.

void beginStep();
void endStep();
void beginDraw();
void endDraw();