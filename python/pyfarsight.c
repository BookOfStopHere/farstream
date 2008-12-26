/* -- THIS FILE IS GENERATED - DO NOT EDIT *//* -*- Mode: C; c-basic-offset: 4 -*- */

#include <Python.h>



#line 3 "pyfarsight.override"
#include <Python.h>
#include <pygobject.h>

#include <gst/gst.h>

#include "fs-conference-iface.h"
#include "fs-enum-types.h"

#include "fs-transmitter.h"
#include "fs-element-added-notifier.h"

static PyObject *
_fs_boxed_list_from_value (const GValue *value, GType listtype, GType type)
{
  PyObject *list = PyList_New (0);
  GList *item;

  if (G_VALUE_TYPE(value) != listtype)
  {
    PyErr_Format(PyExc_TypeError, "Must be a List of %s", g_type_name (type));
    return NULL;
  }

  for (item = g_list_first (g_value_get_boxed (value));
       item;
       item = g_list_next (item))
    PyList_Append (list, pyg_boxed_new (type, item->data, TRUE, TRUE));

  return list;
}

typedef void* (*StructCopyFunc) (void*);

static int
_fs_boxed_list_to_value (GValue *value, PyObject *obj, GType type,
    StructCopyFunc copy_func)
{
  int i;
  GList *boxed = NULL;

  if (!PySequence_Check (obj)) {
    PyErr_Format(PyExc_TypeError, "Must be a List of %s", g_type_name (type));
    return -1;
  }

  for (i = 0; i < PySequence_Size (obj); i++)
  {
    PyObject *item = PySequence_GetItem (obj, i);

    if (!pyg_boxed_check (item, type))
    {
      PyErr_Format(PyExc_TypeError,
          "The parameter must be a List of %s", g_type_name (type));
      return -1;
    }
  }

  for (i = 0; i < PySequence_Size (obj); i++)
  {
    PyObject *item = PySequence_GetItem (obj, i);

    boxed = g_list_append (boxed,
        copy_func (
            pyg_boxed_get (item, void*)));
  }

  g_value_take_boxed (value, boxed);

  return 0;
}

static PyObject *
_fs_codec_list_from_value (const GValue *value)
{
  return _fs_boxed_list_from_value (value,
      FS_TYPE_CODEC_LIST,
      FS_TYPE_CODEC);
}

static int
_fs_codec_list_to_value (GValue *value, PyObject *obj)
{
  return _fs_boxed_list_to_value (value, obj,
      FS_TYPE_CODEC,
      (StructCopyFunc) fs_codec_copy);
}

static PyObject *
_fs_candidate_list_from_value (const GValue *value)
{
  return _fs_boxed_list_from_value (value,
      FS_TYPE_CANDIDATE_LIST,
      FS_TYPE_CANDIDATE);
}

static int
_fs_candidate_list_to_value (GValue *value, PyObject *obj)
{
  return _fs_boxed_list_to_value (value, obj,
      FS_TYPE_CANDIDATE,
      (StructCopyFunc) fs_candidate_copy);
}

#line 112 "pyfarsight.c"


/* ---------- types from other modules ---------- */
static PyTypeObject *_PyGObject_Type;
#define PyGObject_Type (*_PyGObject_Type)
static PyTypeObject *_PyGstPad_Type;
#define PyGstPad_Type (*_PyGstPad_Type)
static PyTypeObject *_PyGstBin_Type;
#define PyGstBin_Type (*_PyGstBin_Type)


/* ---------- forward type declarations ---------- */
PyTypeObject G_GNUC_INTERNAL PyFsCodec_Type;
PyTypeObject G_GNUC_INTERNAL PyFsCandidate_Type;
PyTypeObject G_GNUC_INTERNAL PyFsSession_Type;
PyTypeObject G_GNUC_INTERNAL PyFsParticipant_Type;
PyTypeObject G_GNUC_INTERNAL PyFsStream_Type;
PyTypeObject G_GNUC_INTERNAL PyFsElementAddedNotifier_Type;
PyTypeObject G_GNUC_INTERNAL PyFsConference_Type;

#line 133 "pyfarsight.c"



/* ----------- FsCodec ----------- */

static int
_wrap_fs_codec_new(PyGBoxed *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "id", "encoding_name", "media_type", "clock_rate", NULL };
    int id;
    char *encoding_name;
    FsMediaType media_type;
    guint clock_rate = 0;
    PyObject *py_media_type = NULL, *py_clock_rate = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"isOO:FsCodec.__init__", kwlist, &id, &encoding_name, &py_media_type, &py_clock_rate))
        return -1;
    if (pyg_enum_get_value(FS_TYPE_MEDIA_TYPE, py_media_type, (gpointer)&media_type))
        return -1;
    if (py_clock_rate) {
        if (PyLong_Check(py_clock_rate))
            clock_rate = PyLong_AsUnsignedLong(py_clock_rate);
        else if (PyInt_Check(py_clock_rate))
            clock_rate = PyInt_AsLong(py_clock_rate);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'clock_rate' must be an int or a long");
        if (PyErr_Occurred())
            return -1;
    }
    self->gtype = FS_TYPE_CODEC;
    self->free_on_dealloc = FALSE;
    self->boxed = fs_codec_new(id, encoding_name, media_type, clock_rate);

    if (!self->boxed) {
        PyErr_SetString(PyExc_RuntimeError, "could not create FsCodec object");
        return -1;
    }
    self->free_on_dealloc = TRUE;
    return 0;
}

static PyObject *
_wrap_fs_codec_destroy(PyObject *self)
{
    
    fs_codec_destroy(pyg_boxed_get(self, FsCodec));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_fs_codec_copy(PyObject *self)
{
    FsCodec *ret;

    
    ret = fs_codec_copy(pyg_boxed_get(self, FsCodec));
    
    /* pyg_boxed_new handles NULL checking */
    return pyg_boxed_new(FS_TYPE_CODEC, ret, TRUE, TRUE);
}

static PyObject *
_wrap_fs_codec_to_string(PyObject *self)
{
    gchar *ret;

    
    ret = fs_codec_to_string(pyg_boxed_get(self, FsCodec));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_fs_codec_are_equal(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "codec2", NULL };
    PyObject *py_codec2;
    int ret;
    FsCodec *codec2 = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:FsCodec.are_equal", kwlist, &py_codec2))
        return NULL;
    if (pyg_boxed_check(py_codec2, FS_TYPE_CODEC))
        codec2 = pyg_boxed_get(py_codec2, FsCodec);
    else {
        PyErr_SetString(PyExc_TypeError, "codec2 should be a FsCodec");
        return NULL;
    }
    
    ret = fs_codec_are_equal(pyg_boxed_get(self, FsCodec), codec2);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_fs_codec_to_gst_caps(PyObject *self)
{
    GstCaps *ret;

    
    ret = fs_codec_to_gst_caps(pyg_boxed_get(self, FsCodec));
    
    /* pyg_boxed_new handles NULL checking */
    return pyg_boxed_new(GST_TYPE_CAPS, ret, TRUE, TRUE);
}

static const PyMethodDef _PyFsCodec_methods[] = {
    { "destroy", (PyCFunction)_wrap_fs_codec_destroy, METH_NOARGS,
      NULL },
    { "copy", (PyCFunction)_wrap_fs_codec_copy, METH_NOARGS,
      NULL },
    { "to_string", (PyCFunction)_wrap_fs_codec_to_string, METH_NOARGS,
      NULL },
    { "are_equal", (PyCFunction)_wrap_fs_codec_are_equal, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "to_gst_caps", (PyCFunction)_wrap_fs_codec_to_gst_caps, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

#line 368 "pyfarsight.override"
static PyObject *
_wrap_fs_codec_tp_getattr(PyObject *self, char *attr)
{
  FsCodec *codec;

  codec = pyg_boxed_get(self, FsCodec);

  if (!strcmp (attr, "id"))
  {
    return PyInt_FromLong(codec->id);
  }
  else if (!strcmp (attr, "encoding_name"))
  {
    return PyString_FromString (codec->encoding_name ? codec->encoding_name : "");
  }
  else if (!strcmp (attr, "media_type"))
  {
    return pyg_enum_from_gtype(FS_TYPE_MEDIA_TYPE, codec->media_type);
  }
  else if (!strcmp (attr, "clock_rate"))
  {
    return PyInt_FromLong(codec->clock_rate);
  }
  else if (!strcmp (attr, "channels"))
  {
    return PyInt_FromLong(codec->channels);
  }
  else if (!strcmp (attr, "optional_params"))
  {
    PyObject *list = PyList_New (0);
    GList *p;

    for (p = g_list_first (codec->optional_params); p; p = g_list_next (p))
    {
      PyObject *tuple = PyTuple_New (2);
      FsCodecParameter *param = p->data;

      if (PyTuple_SetItem (tuple, 0,
              PyString_FromString (param->name ? param->name : "")) < 0 ||
          PyTuple_SetItem (tuple, 1,
              PyString_FromString (param->value ? param->value : "")) < 0 ||
          PyList_Append (list, tuple) < 0)
      {
        Py_DECREF (list);
        Py_DECREF (tuple);
        Py_INCREF(Py_None);
        return Py_None;
      }
    }

    return list;
  }
  else
  {
    return Py_FindMethod((PyMethodDef*)_PyFsCodec_methods, self, attr);
  }
}
#line 321 "pyfarsight.c"


#line 249 "pyfarsight.override"
static int
_wrap_fs_codec_tp_setattr(PyObject *self, char *attr, PyObject *value)
{
  FsCodec *codec;

  codec = pyg_boxed_get(self, FsCodec);

  if (!strcmp (attr, "id"))
  {
    if (!PyInt_Check(value))
    {
      PyErr_Format(PyExc_TypeError, "%s must be an int", attr);
      return -1;
    }
    codec->id = (gint)PyInt_AsLong(value);
  }
  else if (!strcmp (attr, "encoding_name"))
  {
    if (value == NULL || PyString_Check(value))
    {
      g_free (codec->encoding_name);
      codec->encoding_name = g_strdup (PyString_AsString (value));
    }
    else
    {
      PyErr_Format(PyExc_TypeError, "%s must be a string", attr);
      return -1;
    }
  }
  else if (!strcmp (attr, "media_type"))
  {
    gint media_type;
    if (pyg_enum_get_value(FS_TYPE_MEDIA_TYPE, value, &media_type))
      return -1;
    codec->media_type = media_type;
  }
  else if (!strcmp (attr, "clock_rate"))
  {
    if (!PyInt_Check(value) || PyInt_AsLong(value) < 0)
    {
      PyErr_Format(PyExc_TypeError, "%s must be an non-negative int", attr);
      return -1;
    }
    codec->clock_rate = (guint)PyInt_AsLong(value);
  }
  else if (!strcmp (attr, "channels"))
  {
    if (!PyInt_Check(value) || PyInt_AsLong(value) < 0)
    {
      PyErr_Format(PyExc_TypeError, "%s must be an non-negative int", attr);
      return -1;
    }
    codec->channels = (guint)PyInt_AsLong(value);
  }
  else if (!strcmp (attr, "optional_params"))
  {
    GList *p;
    GList *newlist = NULL;
    int i = 0;

    if (value == NULL)
      goto none;

    if (!PySequence_Check (value))
    {
      PyErr_Format(PyExc_TypeError, "%s must be a sequence of (name, value)",
          attr);
      return -1;
    }

    for (i = 0; i < PySequence_Size (value); i++)
    {
      PyObject *item = PySequence_GetItem (value, i);

      if (!PyTuple_Check (item) ||
          PyTuple_Size (item) != 2 ||
          !PyString_Check (PyTuple_GetItem (item, 0)) ||
          !PyString_Check (PyTuple_GetItem (item, 1)))
      {
        PyErr_Format(PyExc_TypeError,
            "%s must be a list of (string name, string value)",
            attr);
        return -1;
      }
    }

    for (i = 0; i < PySequence_Size (value); i++)
    {
      PyObject *item = PySequence_GetItem (value, i);
      FsCodecParameter *param = g_new0 (FsCodecParameter, 1);

      param->name = g_strdup (PyString_AsString (PyTuple_GetItem (item, 0)));
      param->value = g_strdup (PyString_AsString (PyTuple_GetItem (item, 1)));
      newlist = g_list_append (newlist, param);
    }

  none:

    for (p = g_list_first (codec->optional_params); p; p = g_list_next (p))
    {
      FsCodecParameter *param = p->data;
      g_free (param->name);
      g_free (param->value);
      g_free (p->data);
    }
    g_list_free (codec->optional_params);
    codec->optional_params = newlist;
  }
  else
  {
    PyErr_Format(PyExc_AttributeError,
        "Attribute %s does not exist for FsCodec", attr);
    return -1;
  }

  return 0;
}
#line 442 "pyfarsight.c"


PyTypeObject G_GNUC_INTERNAL PyFsCodec_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "farsight.Codec",                   /* tp_name */
    sizeof(PyGBoxed),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)_wrap_fs_codec_tp_getattr,       /* tp_getattr */
    (setattrfunc)_wrap_fs_codec_tp_setattr,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyFsCodec_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_fs_codec_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- FsCandidate ----------- */

#line 427 "pyfarsight.override"
static int
_wrap_fs_candidate_new(PyGBoxed *self)
{
  self->gtype = FS_TYPE_CANDIDATE;
  self->free_on_dealloc = FALSE;
  self->boxed = g_new0 (FsCandidate, 1);

  if (!self->boxed) {
    PyErr_SetString(PyExc_RuntimeError, "could not create FsCodec object");
    return -1;
  }
  self->free_on_dealloc = TRUE;

  return 0;
}
#line 510 "pyfarsight.c"


static PyObject *
_wrap_fs_candidate_destroy(PyObject *self)
{
    
    fs_candidate_destroy(pyg_boxed_get(self, FsCandidate));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_fs_candidate_copy(PyObject *self)
{
    FsCandidate *ret;

    
    ret = fs_candidate_copy(pyg_boxed_get(self, FsCandidate));
    
    /* pyg_boxed_new handles NULL checking */
    return pyg_boxed_new(FS_TYPE_CANDIDATE, ret, TRUE, TRUE);
}

static PyObject *
_wrap_fs_candidate_are_equal(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "cand2", NULL };
    PyObject *py_cand2;
    int ret;
    FsCandidate *cand2 = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:FsCandidate.are_equal", kwlist, &py_cand2))
        return NULL;
    if (pyg_boxed_check(py_cand2, FS_TYPE_CANDIDATE))
        cand2 = pyg_boxed_get(py_cand2, FsCandidate);
    else {
        PyErr_SetString(PyExc_TypeError, "cand2 should be a FsCandidate");
        return NULL;
    }
    
    ret = fs_candidate_are_equal(pyg_boxed_get(self, FsCandidate), cand2);
    
    return PyBool_FromLong(ret);

}

static const PyMethodDef _PyFsCandidate_methods[] = {
    { "destroy", (PyCFunction)_wrap_fs_candidate_destroy, METH_NOARGS,
      NULL },
    { "copy", (PyCFunction)_wrap_fs_candidate_copy, METH_NOARGS,
      NULL },
    { "are_equal", (PyCFunction)_wrap_fs_candidate_are_equal, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

#line 530 "pyfarsight.override"
static PyObject *
_wrap_fs_candidate_tp_getattr(PyObject *self, char *attr)
{
  FsCandidate *candidate;

  candidate = pyg_boxed_get(self, FsCandidate);

#define CHECK_NULL(x) ((x) == NULL ? "" : (x))

  if (!strcmp (attr, "candidate_id"))
    return PyString_FromString (CHECK_NULL(candidate->candidate_id));
  else if (!strcmp (attr, "foundation"))
    return PyString_FromString (CHECK_NULL(candidate->foundation));
  else if (!strcmp (attr, "component_id"))
    return PyInt_FromLong(candidate->component_id);
  else if (!strcmp (attr, "ip"))
    return PyString_FromString (CHECK_NULL(candidate->ip));
  else if (!strcmp (attr, "port"))
    return PyInt_FromLong(candidate->port);
  else if (!strcmp (attr, "base_ip"))
    return PyString_FromString (CHECK_NULL(candidate->base_ip));
  else if (!strcmp (attr, "base_port"))
    return PyInt_FromLong(candidate->base_port);
  else if (!strcmp (attr, "priority"))
    return PyInt_FromLong(candidate->priority);
  else if (!strcmp (attr, "ttl"))
    return PyInt_FromLong(candidate->ttl);
  else if (!strcmp (attr, "username"))
    return PyString_FromString (CHECK_NULL(candidate->username));
  else if (!strcmp (attr, "password"))
    return PyString_FromString (CHECK_NULL(candidate->password));
  else if (!strcmp (attr, "proto"))
    return pyg_enum_from_gtype(FS_TYPE_NETWORK_PROTOCOL, candidate->proto);
  else if (!strcmp (attr, "type"))
    return pyg_enum_from_gtype(FS_TYPE_CANDIDATE_TYPE, candidate->type);
  else
    return Py_FindMethod((PyMethodDef*)_PyFsCodec_methods, self, attr);

#undef CHECK_NULL
}
#line 609 "pyfarsight.c"


#line 446 "pyfarsight.override"
static int
_wrap_fs_candidate_tp_setattr(PyObject *self, char *attr, PyObject *value)
{
  FsCandidate *candidate;

  candidate = pyg_boxed_get(self, FsCandidate);

#define CHECK_SET_INT(var, min, max)                                    \
  do {                                                                  \
    if (!PyInt_Check(value) ||                                          \
        PyInt_AsLong(value) < (min) ||                                  \
        PyInt_AsLong(value) > (max))                                    \
    {                                                                   \
      PyErr_Format(PyExc_TypeError, "%s must be an int between %d and %d", \
          attr, min, max);                                              \
      return -1;                                                        \
    }                                                                   \
    candidate->var = PyInt_AsLong(value);                               \
  } while (0)
#define CHECK_SET_STR(var)                                              \
  do {                                                                  \
    if (value && !PyString_Check (value))                               \
    {                                                                   \
      PyErr_Format(PyExc_TypeError, "%s must be a string", attr);       \
      return -1;                                                        \
    }                                                                   \
    g_free ((gpointer*)candidate->var);                                 \
    if (value)                                                          \
      candidate->var = g_strdup (PyString_AsString (value));            \
    else                                                                \
      candidate->var = NULL;                                            \
  } while(0)



  if (!strcmp (attr, "candidate_id"))
    CHECK_SET_STR (candidate_id);
  else if (!strcmp (attr, "foundation"))
    CHECK_SET_STR (foundation);
  else if (!strcmp (attr, "component_id"))
    CHECK_SET_INT (component_id, 1, 256);
  else if (!strcmp (attr, "ip"))
    CHECK_SET_STR (ip);
  else if (!strcmp (attr, "port"))
    CHECK_SET_INT (port, 0, G_MAXUINT16);
  else if (!strcmp (attr, "base_ip"))
    CHECK_SET_STR (base_ip);
  else if (!strcmp (attr, "base_port"))
    CHECK_SET_INT (base_port, 0, G_MAXUINT16);
  else if (!strcmp (attr, "priority"))
    CHECK_SET_INT (priority, G_MININT, G_MAXINT);
  else if (!strcmp (attr, "ttl"))
    CHECK_SET_INT (ttl, 0, 255);
  else if (!strcmp (attr, "username"))
    CHECK_SET_STR (username);
  else if (!strcmp (attr, "password"))
    CHECK_SET_STR (password);
  else if (!strcmp (attr, "proto"))
  {
   gint proto;
    if (pyg_enum_get_value(FS_TYPE_NETWORK_PROTOCOL, value, &proto))
      return -1;
    candidate->proto = proto;
  }
  else if (!strcmp (attr, "type"))
  {
    gint type;
    if (pyg_enum_get_value(FS_TYPE_CANDIDATE_TYPE, value, &type))
      return -1;
    candidate->type = type;
  }
  else
  {
    PyErr_Format(PyExc_AttributeError,
        "Attribute %s does not exist for FsCandidate", attr);
    return -1;
  }

  return 0;
#undef CHECK_SET_INT
#undef CHECK_SET_STR
}
#line 695 "pyfarsight.c"


PyTypeObject G_GNUC_INTERNAL PyFsCandidate_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "farsight.Candidate",                   /* tp_name */
    sizeof(PyGBoxed),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)_wrap_fs_candidate_tp_getattr,       /* tp_getattr */
    (setattrfunc)_wrap_fs_candidate_tp_setattr,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyFsCandidate_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_fs_candidate_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- FsSession ----------- */

#line 131 "pyfarsight.override"
static PyObject *
_wrap_fs_session_new_stream(PyGObject *self, PyObject *args, PyObject *kwargs)
{
  static char *kwlist[] = {"participant", "direction", "transmitter",
                           "transmitter_parameters", NULL};

  PyObject *participant = NULL;
  gint direction;
  const gchar *transmitter_name = NULL;
  PyObject *st_params = NULL;
  int pos = 0, i = 0;
  PyObject *key, *value;
  FsTransmitter *transmitter = NULL;
  GObjectClass *st_class  = NULL;
  GError *error = NULL;
  FsStream *stream = NULL;
  guint n_parameters = 0;
  GParameter *parameters = NULL;

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!is|O!:FsSession.new_stream",
          kwlist,
          &PyFsParticipant_Type, &participant,
          &direction,
          &transmitter_name,
          &PyDict_Type, &st_params))
    return NULL;

  if (st_params)
  {
    n_parameters = PyDict_Size (st_params);

    parameters = g_new0 (GParameter, n_parameters);

    transmitter = fs_transmitter_new (transmitter_name, 2, &error);
    if (!transmitter)
      goto error;

    st_class = g_type_class_ref (
        fs_transmitter_get_stream_transmitter_type (
            transmitter, &error));
    if (!st_class)
      goto error;

    if (!FS_IS_STREAM_TRANSMITTER_CLASS (st_class))
    {
      PyErr_SetString (PyExc_TypeError, "Invalid transmitter name passed");
      goto error;
    }

    while (PyDict_Next(st_params, &pos, &key, &value))
    {
      GParamSpec *spec;

      if (!PyString_Check (key))
      {
        PyErr_SetString (PyExc_TypeError,
            "Expected Stream Parameter key to be a string");
        goto error;
      }

      spec = g_object_class_find_property (st_class, PyString_AsString (key));

      if (!spec)
      {
        PyErr_Format (PyExc_TypeError, "Received unknown key %s",
            PyString_AsString (key));
        goto error;
      }

      g_value_init (&parameters[i].value, G_PARAM_SPEC_VALUE_TYPE(spec));

      parameters[i].name = PyString_AsString (key);

      if (pyg_value_from_pyobject (&parameters[i].value , value) < 0)
      {
        PyErr_Format (PyExc_TypeError, "Expected parameter %s to be a %s",
            PyString_AsString (key),
            g_type_name (G_PARAM_SPEC_VALUE_TYPE(spec)));
        goto error;
      }

      i++;
    }
  }

  stream = fs_session_new_stream (FS_SESSION (pygobject_get (self)),
      FS_PARTICIPANT (pygobject_get (participant)),
      direction,
      transmitter_name, n_parameters, parameters,
      &error);

  if (!stream)
    goto error;

  if (parameters)
  {
    g_type_class_unref (st_class);
    g_free (parameters);
    g_object_unref (transmitter);
  }

  return pygobject_new (G_OBJECT (stream));

 error:
  if (error)
    pyg_error_check (&error);

  if (st_class)
    g_type_class_unref (st_class);
  if (parameters)
    g_free (parameters);
  if (transmitter)
    g_object_unref (transmitter);

  return NULL;
}
#line 864 "pyfarsight.c"


static PyObject *
_wrap_fs_session_start_telephony_event(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "event", "volume", "method", NULL };
    int event, volume, ret;
    PyObject *py_method = NULL;
    FsDTMFMethod method;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"iiO:FsSession.start_telephony_event", kwlist, &event, &volume, &py_method))
        return NULL;
    if (pyg_enum_get_value(FS_TYPE_DTMF_METHOD, py_method, (gpointer)&method))
        return NULL;
    
    ret = fs_session_start_telephony_event(FS_SESSION(self->obj), event, volume, method);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_fs_session_stop_telephony_event(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "method", NULL };
    PyObject *py_method = NULL;
    int ret;
    FsDTMFMethod method;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:FsSession.stop_telephony_event", kwlist, &py_method))
        return NULL;
    if (pyg_enum_get_value(FS_TYPE_DTMF_METHOD, py_method, (gpointer)&method))
        return NULL;
    
    ret = fs_session_stop_telephony_event(FS_SESSION(self->obj), method);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_fs_session_set_send_codec(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "send_codec", NULL };
    PyObject *py_send_codec;
    int ret;
    GError *error = NULL;
    FsCodec *send_codec = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:FsSession.set_send_codec", kwlist, &py_send_codec))
        return NULL;
    if (pyg_boxed_check(py_send_codec, FS_TYPE_CODEC))
        send_codec = pyg_boxed_get(py_send_codec, FsCodec);
    else {
        PyErr_SetString(PyExc_TypeError, "send_codec should be a FsCodec");
        return NULL;
    }
    
    ret = fs_session_set_send_codec(FS_SESSION(self->obj), send_codec, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_fs_session_emit_error(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "error_no", "error_msg", "debug_msg", NULL };
    int error_no;
    char *error_msg, *debug_msg;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"iss:FsSession.emit_error", kwlist, &error_no, &error_msg, &debug_msg))
        return NULL;
    
    fs_session_emit_error(FS_SESSION(self->obj), error_no, error_msg, debug_msg);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyFsSession_methods[] = {
    { "new_stream", (PyCFunction)_wrap_fs_session_new_stream, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "start_telephony_event", (PyCFunction)_wrap_fs_session_start_telephony_event, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "stop_telephony_event", (PyCFunction)_wrap_fs_session_stop_telephony_event, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_send_codec", (PyCFunction)_wrap_fs_session_set_send_codec, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "emit_error", (PyCFunction)_wrap_fs_session_emit_error, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyFsSession_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "farsight.Session",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyFsSession_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- FsParticipant ----------- */

PyTypeObject G_GNUC_INTERNAL PyFsParticipant_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "farsight.Participant",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- FsStream ----------- */

static PyObject *
_wrap_fs_stream_add_remote_candidate(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "candidate", NULL };
    PyObject *py_candidate;
    int ret;
    GError *error = NULL;
    FsCandidate *candidate = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:FsStream.add_remote_candidate", kwlist, &py_candidate))
        return NULL;
    if (pyg_boxed_check(py_candidate, FS_TYPE_CANDIDATE))
        candidate = pyg_boxed_get(py_candidate, FsCandidate);
    else {
        PyErr_SetString(PyExc_TypeError, "candidate should be a FsCandidate");
        return NULL;
    }
    
    ret = fs_stream_add_remote_candidate(FS_STREAM(self->obj), candidate, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_fs_stream_remote_candidates_added(PyGObject *self)
{
    
    fs_stream_remote_candidates_added(FS_STREAM(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_fs_stream_select_candidate_pair(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "lfoundation", "rfoundation", NULL };
    char *lfoundation, *rfoundation;
    int ret;
    GError *error = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ss:FsStream.select_candidate_pair", kwlist, &lfoundation, &rfoundation))
        return NULL;
    
    ret = fs_stream_select_candidate_pair(FS_STREAM(self->obj), lfoundation, rfoundation, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    return PyBool_FromLong(ret);

}

#line 572 "pyfarsight.override"
static PyObject *
_wrap_fs_stream_set_remote_codecs (PyGObject *self, PyObject *arg)
{
  gboolean ret = FALSE;
  GError *error = NULL;
  GList *codecs = NULL;
  int i;

  if (!PySequence_Check (arg))
  {
    PyErr_SetString (PyExc_TypeError,
        "The parameter must be a List of FsCodec");
    return NULL;
  }

  if (PySequence_Size (arg) == 0)
  {
    PyErr_SetString (PyExc_TypeError,
        "Empty list invalid");
    return NULL;
  }

  for (i = 0; i < PySequence_Size (arg); i++)
  {
    PyObject *item = PySequence_GetItem (arg, i);

    if (!pyg_boxed_check (item, FS_TYPE_CODEC))
    {
      PyErr_SetString(PyExc_TypeError,
          "The parameter must be a List of FsCodec");
      return NULL;
    }
  }

  for (i = 0; i < PySequence_Size (arg); i++)
  {
    PyObject *item = PySequence_GetItem (arg, i);

    codecs = g_list_append (codecs, pyg_boxed_get (item, FsCodec));
  }

  ret = fs_stream_set_remote_codecs (FS_STREAM(self->obj), codecs, &error);

  g_list_free (codecs);

  if (pyg_error_check(&error))
    return NULL;

  return PyBool_FromLong (ret);
}
#line 1165 "pyfarsight.c"


static PyObject *
_wrap_fs_stream_emit_error(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "error_no", "error_msg", "debug_msg", NULL };
    int error_no;
    char *error_msg, *debug_msg;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"iss:FsStream.emit_error", kwlist, &error_no, &error_msg, &debug_msg))
        return NULL;
    
    fs_stream_emit_error(FS_STREAM(self->obj), error_no, error_msg, debug_msg);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_fs_stream_emit_src_pad_added(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "pad", "codec", NULL };
    PyGObject *pad;
    PyObject *py_codec;
    FsCodec *codec = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!O:FsStream.emit_src_pad_added", kwlist, &PyGstPad_Type, &pad, &py_codec))
        return NULL;
    if (pyg_boxed_check(py_codec, FS_TYPE_CODEC))
        codec = pyg_boxed_get(py_codec, FsCodec);
    else {
        PyErr_SetString(PyExc_TypeError, "codec should be a FsCodec");
        return NULL;
    }
    
    fs_stream_emit_src_pad_added(FS_STREAM(self->obj), GST_PAD(pad->obj), codec);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyFsStream_methods[] = {
    { "add_remote_candidate", (PyCFunction)_wrap_fs_stream_add_remote_candidate, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "remote_candidates_added", (PyCFunction)_wrap_fs_stream_remote_candidates_added, METH_NOARGS,
      NULL },
    { "select_candidate_pair", (PyCFunction)_wrap_fs_stream_select_candidate_pair, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_remote_codecs", (PyCFunction)_wrap_fs_stream_set_remote_codecs, METH_O,
      NULL },
    { "emit_error", (PyCFunction)_wrap_fs_stream_emit_error, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "emit_src_pad_added", (PyCFunction)_wrap_fs_stream_emit_src_pad_added, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyFsStream_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "farsight.Stream",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyFsStream_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- FsElementAddedNotifier ----------- */

static int
_wrap_fs_element_added_notifier_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":farsight.ElementAddedNotifier.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create farsight.ElementAddedNotifier object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_fs_element_added_notifier_add(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "bin", NULL };
    PyGObject *bin;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:FsElementAddedNotifier.add", kwlist, &PyGstBin_Type, &bin))
        return NULL;
    
    fs_element_added_notifier_add(FS_ELEMENT_ADDED_NOTIFIER(self->obj), GST_BIN(bin->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_fs_element_added_notifier_remove(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "bin", NULL };
    PyGObject *bin;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:FsElementAddedNotifier.remove", kwlist, &PyGstBin_Type, &bin))
        return NULL;
    
    ret = fs_element_added_notifier_remove(FS_ELEMENT_ADDED_NOTIFIER(self->obj), GST_BIN(bin->obj));
    
    return PyBool_FromLong(ret);

}

static const PyMethodDef _PyFsElementAddedNotifier_methods[] = {
    { "add", (PyCFunction)_wrap_fs_element_added_notifier_add, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "remove", (PyCFunction)_wrap_fs_element_added_notifier_remove, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyFsElementAddedNotifier_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "farsight.ElementAddedNotifier",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyFsElementAddedNotifier_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_fs_element_added_notifier_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- FsConference ----------- */

static PyObject *
_wrap_fs_conference_new_session(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "media_type", NULL };
    PyObject *py_media_type = NULL;
    FsMediaType media_type;
    GError *error = NULL;
    FsSession *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:FsConference.new_session", kwlist, &py_media_type))
        return NULL;
    if (pyg_enum_get_value(FS_TYPE_MEDIA_TYPE, py_media_type, (gpointer)&media_type))
        return NULL;
    
    ret = fs_conference_new_session(FS_CONFERENCE(self->obj), media_type, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_fs_conference_new_participant(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "cname", NULL };
    char *cname;
    FsParticipant *ret;
    GError *error = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:FsConference.new_participant", kwlist, &cname))
        return NULL;
    
    ret = fs_conference_new_participant(FS_CONFERENCE(self->obj), cname, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static const PyMethodDef _PyFsConference_methods[] = {
    { "new_session", (PyCFunction)_wrap_fs_conference_new_session, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "new_participant", (PyCFunction)_wrap_fs_conference_new_participant, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyFsConference_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "farsight.Conference",                   /* tp_name */
    sizeof(PyObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyFsConference_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- functions ----------- */

const PyMethodDef fs_functions[] = {
    { NULL, NULL, 0, NULL }
};


/* ----------- enums and flags ----------- */

void
fs_add_constants(PyObject *module, const gchar *strip_prefix)
{
#ifdef VERSION
    PyModule_AddStringConstant(module, "__version__", VERSION);
#endif
  pyg_enum_add(module, "MediaType", strip_prefix, FS_TYPE_MEDIA_TYPE);
  pyg_enum_add(module, "CandidateType", strip_prefix, FS_TYPE_CANDIDATE_TYPE);
  pyg_enum_add(module, "NetworkProtocol", strip_prefix, FS_TYPE_NETWORK_PROTOCOL);
  pyg_enum_add(module, "ComponentType", strip_prefix, FS_TYPE_COMPONENT_TYPE);
  pyg_enum_add(module, "Error", strip_prefix, FS_TYPE_ERROR);
  pyg_enum_add(module, "DTMFEvent", strip_prefix, FS_TYPE_DTMF_EVENT);
  pyg_enum_add(module, "DTMFMethod", strip_prefix, FS_TYPE_DTMF_METHOD);
  pyg_flags_add(module, "StreamDirection", strip_prefix, FS_TYPE_STREAM_DIRECTION);

  if (PyErr_Occurred())
    PyErr_Print();
}

/* initialise stuff extension classes */
void
fs_register_classes(PyObject *d)
{
    PyObject *module;

    if ((module = PyImport_ImportModule("gobject")) != NULL) {
        _PyGObject_Type = (PyTypeObject *)PyObject_GetAttrString(module, "GObject");
        if (_PyGObject_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name GObject from gobject");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gobject");
        return ;
    }
    if ((module = PyImport_ImportModule("gst")) != NULL) {
        _PyGstPad_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Pad");
        if (_PyGstPad_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Pad from gst");
            return ;
        }
        _PyGstBin_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Bin");
        if (_PyGstBin_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Bin from gst");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gst");
        return ;
    }


#line 123 "pyfarsight.override"
pyg_register_gtype_custom (FS_TYPE_CODEC_LIST,
    _fs_codec_list_from_value,
    _fs_codec_list_to_value);
pyg_register_gtype_custom (FS_TYPE_CANDIDATE_LIST,
    _fs_candidate_list_from_value,
    _fs_candidate_list_to_value);

#line 1550 "pyfarsight.c"
    pyg_register_boxed(d, "Codec", FS_TYPE_CODEC, &PyFsCodec_Type);
    pyg_register_boxed(d, "Candidate", FS_TYPE_CANDIDATE, &PyFsCandidate_Type);
    pyg_register_interface(d, "Conference", FS_TYPE_CONFERENCE, &PyFsConference_Type);
    pygobject_register_class(d, "FsSession", FS_TYPE_SESSION, &PyFsSession_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(FS_TYPE_SESSION);
    pygobject_register_class(d, "FsParticipant", FS_TYPE_PARTICIPANT, &PyFsParticipant_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(FS_TYPE_PARTICIPANT);
    pygobject_register_class(d, "FsStream", FS_TYPE_STREAM, &PyFsStream_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(FS_TYPE_STREAM);
    pygobject_register_class(d, "FsElementAddedNotifier", FS_TYPE_ELEMENT_ADDED_NOTIFIER, &PyFsElementAddedNotifier_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(FS_TYPE_ELEMENT_ADDED_NOTIFIER);
}
