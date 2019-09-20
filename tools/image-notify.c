/*
 * Copyright (C) 2019 Zander Brown
 * SPDX-License-Identifier: GPL-3.0+
 * Author: Zander Brown <zbrown@gnome.org>
 */

#include <glib.h>
#include <gio/gio.h>

static void
activate (GApplication *app)
{
  g_autoptr (GNotification) noti = NULL;
  g_autoptr (GIcon) icon = NULL;

  icon = g_themed_icon_new ("start-here");

  noti = g_notification_new ("Hello, World!");
  g_notification_set_body (noti, "A <i>whole</i> <b>world</b> of fun :-)");
  g_notification_set_icon (noti, icon);

  g_notification_add_button (noti, "Test", "app.test");
  g_notification_add_button (noti, "Me", "app.test");

  g_application_send_notification (app, "test", noti);
}

int
main (int argc, char **argv)
{
  GApplication *app;

  app = g_application_new ("sm.puri.phosh.NotifyTest",
                           G_APPLICATION_FLAGS_NONE);

  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

  return g_application_run (G_APPLICATION (app), argc, argv);
}