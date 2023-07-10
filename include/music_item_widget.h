/*
    Derived widget from Gtk::Box.

    Widget para facilitar a criação de elementos music_item.
*/

#ifndef MUSIC_ITEM_WIDGET
#define MUSIC_ITEM_WIDGET

#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <gtkmm/builder.h>
#include <gtkmm/eventbox.h>
#include "musica.h"

class MusicItem : public Gtk::Box {
public:
    MusicItem(
        BaseObjectType* cobject, 
        const Glib::RefPtr<Gtk::Builder>& builder,
        bool is_playlist = false
    );
    virtual ~MusicItem();

    void setMusic(Musica* musica);
    void setId(int id);

    void setTitle(const std::string& str);
    void setCover(const std::string& file_path);
    void setArtist(const std::string& str);
    void setDuration(const std::string& str);

    // Method to handle the like click event
    bool onLikeClicked(GdkEventButton* event);

protected:
    Musica* music; // Music object which this widget is related to.
    int id;
    bool is_liked;

    Glib::RefPtr<Gtk::Builder> builder;
    Gtk::Box* cover_wrapper;
    Gtk::Image* type_icon;
    Gtk::Label* type_text;
    Gtk::EventBox* like_wrapper;
    Gtk::Image* like_icon;
    Gtk::Label* title;
    Gtk::Label* artist;
    Gtk::Image* artist_icon;
    Gtk::Label* duration;

};

#endif