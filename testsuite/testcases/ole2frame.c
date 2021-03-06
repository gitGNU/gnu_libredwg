#include "common.c"

void output_process (dwg_object * obj);

void
output_object (dwg_object * obj)
{
  if (!obj)
    {
      printf ("object is NULL\n");
      return;
    }

  if (dwg_get_type (obj) == DWG_TYPE_OLE2FRAME)
    {
      output_process (obj);
    }
}

void
low_level_process (dwg_object * obj)
{

  // casts dwg object to ole2frame entity
  dwg_ent_ole2frame *ole2frame = dwg_object_to_OLE2FRAME (obj);

  // prints flags
  printf ("flags of ole2frame : %ud\t\n", ole2frame->flags);

  // prints mode
  printf ("mode of ole2frame : %ud\t\n", ole2frame->mode);

  // prints data length
  printf ("data length of ole2frame : %ld\t\n", ole2frame->data_length);

  // prints data
  printf ("data of ole2frame : %s\t\n", ole2frame->data);
}

void
api_process (dwg_object * obj)
{
  int flags_error, mode_error, data_length_error, data_error;
  unsigned int flags, mode;
  long data_length;
  char *data;
  dwg_ent_ole2frame *ole2frame = dwg_object_to_OLE2FRAME (obj);

  // returns flags
  flags = dwg_ent_ole2frame_get_flags (ole2frame, &flags_error);
  if (flags_error == 0 && flags == ole2frame->flags)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading flags");
    }

  // returns mode
  mode = dwg_ent_ole2frame_get_mode (ole2frame, &mode_error);
  if (mode_error == 0 && mode == ole2frame->mode)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading mode");
    }

  // returns length of data
  data_length =
    dwg_ent_ole2frame_get_data_length (ole2frame, &data_length_error);
  if (data_length_error == 0 && data_length == ole2frame->data_length)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in data length");
    }

  // returns data
  data = dwg_ent_ole2frame_get_data (ole2frame, &data_error);
  if (data_error == 0 && ole2frame->data == data)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading data");
    }


}
