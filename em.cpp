#include <iostream>
#include <string>
#include <vector>

using namespace std;

void WaitFor(string message) {
	while (true) {
		string i;
		getline(cin, i);
		if (i == message) {
			break;
		}
	}
}

void Action(string command, bool waitUntilSuccess) {
	cout << ("start " + command) << endl;
	if (waitUntilSuccess) {
		WaitFor("succeeded " + command);
	}
}

int main() {
		//Place Creations
		Action("CreatePlace(CurrentTown, City)", true);
		Action("CreatePlace(CurrentForestPath, ForestPath)", true);
		Action("CreatePlace(CurrentRuins, Ruins)", true);
		//Arlon Character
		Action("CreateCharacter(Arlon, B)", true);
		Action("SetClothing(Arlon, LightArmour)", true);
		Action("SetHairStyle(Arlon, Long)", true);
		Action("SetPosition(Arlon, CurrentTown.Fountain)", true);
		//Mariah Character
		Action("CreateCharacter(Mariah, G)", true);
		Action("SetClothing(Mariah, Beggar)", true);
		Action("SetHairStyle(Mariah, Straight)", true);
		Action("SetHairColor(Mariah, Gray)", true);
		Action("SetPosition(Mariah, CurrentForestPath.Well)", true);

		//Items
		Action("CreateItem(MathiasSword, Sword)", true);
		Action("CreateItem(ArchieSpellbook, SpellBook)", true);

		//Icons
		Action("EnableIcon(Talk_To_Mariah, Talk, Mariah, Talk To Mariah, true)", true);
		Action("EnableIcon(Take_MathiasSword, Coins, MathiasSword, Take the sword, true)", true);
		Action("EnableIcon(Take_ArchieSpellbook, Coins, ArchieSpellbook, Take the spellbook, true)", true);

		//Menu
		Action("ShowMenu()", true);

		Action("EnableEffect(CurrentRuins.Altar, Resurrection)", true);

		//Inventories
		vector<string> playerInv;
		vector<string> mariahInv;
		mariahInv.push_back("MathiasSword");
		mariahInv.push_back("ArchieSpellbook");
		playerInv.push_back("MathiasSword");
		playerInv.push_back("ArchieSpellbook");


		while (true) {
			string i;
			getline(cin, i);
			if (i == "input Selected Start") {
				Action("SetCameraFocus(Arlon)", true);
				Action("HideMenu()", true);
				Action("EnableInput()", true);
			}

			else if (i == "input arrived Arlon position CurrentTown.EastEnd") {
				Action("Exit(Arlon, CurrentTown.EastEnd, true)", true);
				Action("Enter(Arlon, CurrentForestPath.WestEnd, true)", true);
			}

			else if (i == "input arrived Arlon position CurrentForestPath.EastEnd") {
				Action("Exit(Arlon, CurrentForestPath.EastEnd, true)", true);
				Action("Enter(Arlon, CurrentRuins.Exit, true)", true);
			}

			else if (i == "input arrived Arlon position CurrentRuins.Altar") {
				Action("SetNarration(Woah this is cray)", true);
				Action("ShowNarration()", true);
			}

			else if (i == "input Key Inventory") {
				Action("ClearList()", true);
				for (string item : playerInv) {
					Action("AddToList(" + item + ")", true);
				}
				Action("ShowList(Arlon)", true);
			}

			else if (i == "input Close List") {
				Action("HideList()", true);
				Action("EnableInput()", true);
			}
		}

	return 0;
}