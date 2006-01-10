
#include <glade.h>
#include <glib.h>

GList*
gladeuisharp_gladeui_widget_get_signals (GladeWidget *widget, const gchar *signal_name)
{
	GList *list = NULL;
	GPtrArray *array;
	int n;
	
	array = glade_widget_list_signal_handlers (widget, signal_name);
	if (array == NULL)
		return NULL;

	for (n = 0; n < array->len; n++)
		list = g_list_append (list, g_ptr_array_index (array, n)); 
	
	return list;
}

GList*
gladeuisharp_gladeui_project_get_objects (GladeProject *project)
{
	return project->objects;
}

gchar*
gladeuisharp_gladeui_project_get_path (GladeProject *project)
{
	return project->path;
}


gboolean
gladeuisharp_gladeui_project_get_modified (GladeProject *project)
{
	return project->changed;
}

void
gladeuisharp_gladeui_interface_init (GladeInterface *interface)
{
	interface->names = g_hash_table_new (g_str_hash, g_str_equal);
	interface->strings = g_hash_table_new_full (g_str_hash,
						    g_str_equal,
						    (GDestroyNotify)g_free,
						    NULL);
}
