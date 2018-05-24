#include "NelderMeadForm.h"
#include "NeldearMead.h"
using namespace System;
using namespace System::Windows::Forms;

int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	NelderMeadMethod::NelderMeadForm form;
	Application::Run(%form);
}