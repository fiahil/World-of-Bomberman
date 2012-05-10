/*
** main.c for plop in /tmp
**
** Made by nicolas magere
** Login   <magere_n@epitech.net>
**
** Started on  Thu May  3 16:03:03 2012 nicolas magere
** Last update Mon May  7 15:23:03 2012 nicolas magere
*/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vlc/vlc.h>

int main(int ac, char **av)
{
  libvlc_instance_t * inst;
  libvlc_media_player_t *mp;
  libvlc_media_t *m;

  if (ac != 2)
    return -1;

  /* Load the VLC engine */
  inst = libvlc_new(0, NULL);

  /* Create a new item */
  m = libvlc_media_new_path(inst, av[1]);

  /* Create a media player playing environement */
  mp = libvlc_media_player_new_from_media(m);

  /* No need to keep the media now */
  libvlc_media_release(m);

  /* Full screen */
  libvlc_toggle_fullscreen(mp);

  /* play the media_player */
  libvlc_media_player_play(mp);

  /* Let it play a bit */
  sleep(30);

  /* Stop playing */
  libvlc_media_player_stop(mp);

  /* Free the media_player */
  libvlc_media_player_release(mp);
  libvlc_release(inst);
  return 0;
}
