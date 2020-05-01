#include "FilmRepository.h"

FilmRepository::FilmRepository()
{
    Filme = {};
}
void FilmRepository::add_Film(string titel, string genre, string link, int jahr, int likes)
{
    for(auto i = Filme.begin();i<Filme.end();i++)
        if(i->get_Titel()==titel)
        {
            cout<<"Der Film existiert schon!";
            break;
        }
    //wenn der Film nicht existiert, wird er eingefuegt
    Filme.emplace_back(Film(titel,genre,link,jahr,likes));
}

void FilmRepository::delete_Film(string titel)
{
    int found=0;
    for(auto i=0;i<Filme.size();i++)
        if(titel == Filme[i].get_Titel())
        {
            Filme.erase(Filme.begin() + i);
            found=1;
        }
    //Der Film existiert nicht
    if(found==0)
        cout<<"Der Film existiert nicht! Bitte den Film einfuegen";
}
Film FilmRepository::search_Film(string titel) {

    for(auto & i : Filme)
        if(i.get_Titel()==titel)
            return i;
    return Film("","","",0,0);
}

vector <Film> FilmRepository::get_all() {
    return Filme;
}

void FilmRepository::Anschreiben()
{
    for(auto i=Filme.begin();i<Filme.end();i++)
        cout<<i->get_Titel()<<" "<<i->get_Genre()<<" "<<i->get_Jahr()<<" "<<i->get_Likes()<<" " <<i->get_Link()<<"\n";
}

void FilmRepository::Bearbeiten(string titel, string genre, string link, int jahr, int likes)
{
    for (auto &i : Filme)
        if (i.get_Titel() == titel) {
            i.set_Genre(genre);
            i.set_Link(link);
            i.set_Likes(likes);
        }
}

void FilmRepository::Ansehen_Genre(string val)
{
    for(auto i=Filme.begin();i<Filme.end();i++)
        if(i->get_Genre()==val)
            cout<<i->get_Titel()<<" "<<i->get_Genre()<<" "<<i->get_Jahr()<<" "<<i->get_Likes()<<" " <<i->get_Link()<<"\n";
}