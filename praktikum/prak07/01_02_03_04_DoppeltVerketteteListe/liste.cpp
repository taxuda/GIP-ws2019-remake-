// Datei: liste.cpp

#include <string>
#include "liste.h"

std::string liste_als_string(TListenKnoten* anker)
{
	std::string resultat = "";

	if (anker == nullptr)
		return "Leere Liste.";
	else
	{
		resultat += "[ ";
		TListenKnoten* ptr = anker;
		do
		{
			resultat += std::to_string(ptr->data);

			if (ptr->next != nullptr) resultat += " , ";
			else resultat += " ";

			ptr = ptr->next;
		} while (ptr != nullptr);
		resultat += "]";
	}

	return resultat;
}
std::string liste_als_string_rueckwaerts(TListenKnoten* anker){
    std::string sListe = "";
    if(anker == nullptr){
        return "Leere Liste.";
    }else{
        sListe = liste_als_string(anker);
        std::reverse(sListe.begin(),sListe.end());
        sListe[0] = '[';
        sListe[sListe.size()-1] = ']';
        return sListe;
    }
}

// Wird modifiziert in Aufgabe INF-07.01 ...
void hinten_anfuegen(TListenKnoten *&anker, const int wert)
{
	TListenKnoten *neuer_eintrag = new TListenKnoten;
	neuer_eintrag->data = wert;
	neuer_eintrag->next = nullptr;
	neuer_eintrag->prev = nullptr;

	if (anker == nullptr)
		anker = neuer_eintrag;
	else
	{
		TListenKnoten *ptr = anker;
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		ptr->next = neuer_eintrag;
		neuer_eintrag->prev = ptr;
	}
}

void in_liste_einfuegen(TListenKnoten* &anker, int wert_neu, int vor_wert){
    TListenKnoten* neuer_eintrag = new TListenKnoten{wert_neu, nullptr, nullptr};
    /*
    if(anker == nullptr){
        anker = neuer_eintrag;
    }else if(anker->data == vor_wert){
        TListenKnoten* tmp = anker;
        anker = neuer_eintrag;
        neuer_eintrag->next = tmp;
        tmp->prev = neuer_eintrag;
    }else{
        TListenKnoten* tmp = anker;
        bool vor_wert_found = false;
        while(tmp != nullptr){
            // tmp->next == nullptr => tmp letzte Knote
            if(tmp->data == vor_wert){

                vor_wert_found = true;
                break;
            }else{
                if(tmp->next == nullptr)
                    break;
                tmp = tmp->next;
            }
        }
        if(vor_wert_found){
            tmp->prev->next = neuer_eintrag;
            neuer_eintrag->prev = tmp->prev;
            neuer_eintrag->next = tmp;
            tmp->prev = neuer_eintrag;
        }else{
            tmp->next = neuer_eintrag;
            neuer_eintrag->prev = tmp;
        }
    }
    */
    if(anker == nullptr){
        anker = neuer_eintrag;
    }else{
        TListenKnoten* nodeFound = nullptr;
        if(find(anker, vor_wert, nodeFound)){   // found Node
            if(nodeFound == anker){ // vorne anker hinzufuegen
                neuer_eintrag->next = anker;
                anker->prev = neuer_eintrag;
                anker = neuer_eintrag;
            }else{
                nodeFound->prev->next = neuer_eintrag;
                neuer_eintrag->prev = nodeFound->prev;
                neuer_eintrag->next = nodeFound;
                nodeFound->prev = neuer_eintrag;
            }
        }else{  // node not found, find() return letzte Knoten - nodeFound
            nodeFound->next = neuer_eintrag;
            neuer_eintrag->prev = nodeFound;
        }
    }
}

bool find(TListenKnoten* const &anker, const int toFind, TListenKnoten* &nodeFound){
    if(anker == nullptr){
        nodeFound = nullptr;
        return false;
    }else{
        TListenKnoten* tmp = anker;
        while(true){
            if(tmp->data == toFind){
                nodeFound = tmp;
                return true;
            }else if(tmp->next == nullptr){ // tmp ist letzte Knoten
                nodeFound = tmp;
                return false;
            }else{
                tmp = tmp->next;
            }
        }
    }
}

void aus_liste_loeschen(TListenKnoten* &anker, int wert){
    if(anker == nullptr) return;

    TListenKnoten* nodeFound = nullptr;
    if(find(anker, wert, nodeFound)){        // node(wert) is found
        if(nodeFound == anker){                 // node is found and identical to anker
            TListenKnoten* tmp = anker->next;
            delete anker;
            anker = tmp;
            if(anker != nullptr) anker->prev = nullptr;
        }else if(nodeFound->next == nullptr){   // node is the end
            nodeFound->prev->next = nullptr;
            delete nodeFound;
            nodeFound = nullptr;
        }else{                                  // node in between the list
            nodeFound->next->prev = nodeFound->prev;
            nodeFound->prev->next = nodeFound->next;
            delete nodeFound;
            nodeFound = nullptr;
        }
    }
    // node isn't found
    // do nothing
}