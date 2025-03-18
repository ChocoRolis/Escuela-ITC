#!/bin/bash
tar -czf /home/rolando_$(date +%F).tar.gz /home/rolando
echo "Backup realizado exitosamente el $(date)" >> root/respaldos.log
