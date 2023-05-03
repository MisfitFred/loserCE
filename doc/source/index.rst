.. loserCE documentation master file, created by
   sphinx-quickstart on Tue Apr 18 08:15:38 2023.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to loserCE's documentation!
===================================

.. toctree::
   :maxdepth: 2
   :caption: Contents:

   uci




Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`

Docs
=================

.. doxygenclass:: chessInterface::uci
   :project: loserCE
   :members:

.. warning:: This documentation is still under construction. 



.. uml::

   class client_loserCE
   class receiver_uci
   class invoker_stdInOut
   class command_cmd
   class concreteCommand_iocmd

   client_loserCE --> receiver_uci
   client_loserCE ..> concreteCommand_iocmd
   concreteCommand_iocmd --> receiver_uci
   command_cmd <|-- concreteCommand_iocmd
   invoker_stdInOut o-- command_cmd

.. uml::

   participant  client_loserCE
   participant  receiver_uci
   participant  invoker_stdInOut
   participant  command_cmd
   participant  concreteCommand_iocmd


   client_loserCE --> concreteCommand_iocmd: new concreteCommand_iocmd(receiver_uci)
   client_loserCE -> invoker_stdInOut: StoreCommand(command_cmd)

   invoker_stdInOut ->command_cmd: Execute()
   command_cmd -> receiver_uci: Action()

.. code-block:: cpp
   :linenos:

   import antigravity

   #define main()
       antigravity.fly()
       