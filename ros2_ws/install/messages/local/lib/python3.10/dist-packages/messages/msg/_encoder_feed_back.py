# generated from rosidl_generator_py/resource/_idl.py.em
# with input from messages:msg/EncoderFeedBack.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EncoderFeedBack(type):
    """Metaclass of message 'EncoderFeedBack'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('messages')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'messages.msg.EncoderFeedBack')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__encoder_feed_back
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__encoder_feed_back
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__encoder_feed_back
            cls._TYPE_SUPPORT = module.type_support_msg__msg__encoder_feed_back
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__encoder_feed_back

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class EncoderFeedBack(metaclass=Metaclass_EncoderFeedBack):
    """Message class 'EncoderFeedBack'."""

    __slots__ = [
        '_enc_right_wheel',
        '_enc_left_wheel',
    ]

    _fields_and_field_types = {
        'enc_right_wheel': 'int32',
        'enc_left_wheel': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.enc_right_wheel = kwargs.get('enc_right_wheel', int())
        self.enc_left_wheel = kwargs.get('enc_left_wheel', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.enc_right_wheel != other.enc_right_wheel:
            return False
        if self.enc_left_wheel != other.enc_left_wheel:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def enc_right_wheel(self):
        """Message field 'enc_right_wheel'."""
        return self._enc_right_wheel

    @enc_right_wheel.setter
    def enc_right_wheel(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enc_right_wheel' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'enc_right_wheel' field must be an integer in [-2147483648, 2147483647]"
        self._enc_right_wheel = value

    @builtins.property
    def enc_left_wheel(self):
        """Message field 'enc_left_wheel'."""
        return self._enc_left_wheel

    @enc_left_wheel.setter
    def enc_left_wheel(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enc_left_wheel' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'enc_left_wheel' field must be an integer in [-2147483648, 2147483647]"
        self._enc_left_wheel = value
