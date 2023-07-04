#include "../include/playlist.h"

Playlist::Playlist(std::string nome, Usuario usuario) : _nome(nome), _usuario(usuario){}

std::string Playlist::get_usuario(){
    return _usuario.get_nome();
}

void Playlist::adicionar_musica(Musica m) {
    for (Musica x : _lista_musica){
        if (m.get_id() == x.get_id()){
            throw musica_repetida_playlist_e();
        }
    }
    _lista_musica.push_back(m);
}

void Playlist::remover_musica(Musica m) {
    for (auto it = _lista_musica.begin(); it != _lista_musica.end(); it++){
        if (it->get_id() = m.get_id()){
            _lista_musica.erase(it);
        }
    }
}
