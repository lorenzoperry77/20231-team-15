#include "../include/playlist.h"

Playlist::Playlist(std::string nome, Usuario usuario) : _nome(nome), _usuario(usuario){}

Playlist::~Playlist(){}

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

// void Playlist::remover_musica(Musica m) {
//     auto it = std::find_if(_lista_musica.begin(), _lista_musica.end(), [&](const Musica& x) {
//         return x.get_id() == m.get_id();
//     });

//     if (it != _lista_musica.end()) {
//         _lista_musica.erase(it);
//     }
// }

// void Playlist::trocar_musica (int musica1, int musica2){
//     if (musica1< 0 || musica1 >= playlist.getTamanho() ||
//         musica2 < 0 || musica2 >= playlist.getTamanho()) {
//         std::cout << "Posições inválidas!" << std::endl;
//         return;
//     } else {
//         std::swap(_lista_musica[musica1], _lista_musica[musica2]);
//     }
// }